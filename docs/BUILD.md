# Bauen, Installieren, Debuggen

Es gibt zwei Wege zur `.fap`: **automatisch über GitHub Actions** (du lädst nur
herunter) oder **lokal mit ufbt**. Beide bauen gegen die offizielle Firmware.

---

## Weg A — GitHub Actions (nichts lokal installieren)

Der Workflow [`.github/workflows/build.yml`](../.github/workflows/build.yml)
baut die App bei jedem Push und auf Knopfdruck.

1. Repo zu GitHub pushen:
   ```bash
   git add -A
   git commit -m "DeviceTest Lab"
   git branch -M main
   git remote add origin https://github.com/<DEIN-NAME>/devicetest_lab.git
   git push -u origin main
   ```
2. Auf GitHub in den Reiter **Actions** gehen → der Lauf **„Build FAP"** startet
   automatisch (oder manuell via **Run workflow**).
3. Nach ~1–2 Minuten: im Lauf ganz unten **Artifacts → `devicetest_lab-fap`**
   herunterladen. Darin liegt `devicetest_lab.fap`.
4. **Feste Release-Datei** (optional):
   ```bash
   git tag v0.1
   git push --tags
   ```
   Die `.fap` erscheint dann unter **Releases** am Tag `v0.1`.

Firmware-Zweig ändern: in der `build.yml` `sdk-channel: release` auf `dev` oder
`rc` setzen.

---

## Weg B — lokal mit ufbt

**Voraussetzung:** Python ≥ 3.8.

```bash
pip install ufbt          # einmalig
cd devicetest_lab

ufbt                      # baut dist/devicetest_lab.fap
ufbt launch               # baut + lädt + startet auf angeschlossenem Flipper (USB)
ufbt vscode_dist          # richtet VS Code (IntelliSense) ein
ufbt cli                  # serielle CLI zum Flipper
```

Beim ersten Lauf lädt `ufbt` automatisch SDK + Toolchain der offiziellen
Firmware herunter. Anderer Zweig:

```bash
ufbt update --channel=release   # stable (Standard)
ufbt update --channel=dev       # Entwicklungsstand
```

> Hinweis: In dieser Cloud-Sandbox ist der Download-Host des SDK durch die
> Netzwerk-Policy gesperrt, deshalb wurde die `.fap` hier **nicht**
> vorgebaut. Auf deinem eigenen Rechner (oder via Weg A) funktioniert es.

---

## Installieren ohne `ufbt launch`

Falls du die `.fap` von Hand aufspielst (aus Actions-Artifact oder `dist/`):

1. `.fap` auf die Flipper-SD-Karte nach `/ext/apps/Tools/` kopieren
   (qFlipper → Datei-Browser, oder SD in den Kartenleser).
2. Am Flipper: **Apps → Tools → DeviceTest Lab**.

Die App muss zur installierten **Firmware-Version** passen. Weicht die API ab,
einfach gegen den passenden `--channel` neu bauen.

---

## Debuggen

- `ufbt cli` → am Flipper `log` eingeben, um Log-Ausgaben zu sehen.
- Im Code mit `FURI_LOG_I("DeviceTest", "wert=%d", x);` loggen.
- Absturz/Reset? Oft Stack zu klein → `stack_size` in `application.fam` erhöhen
  (z. B. `2 * 4096`), wenn ein Modul viel Speicher braucht.
- `ufbt launch` zeigt Compiler-Fehler mit Datei/Zeile direkt im Terminal.
