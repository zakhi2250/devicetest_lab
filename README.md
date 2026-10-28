# DeviceTest Lab

Ein **modulares Test-Labor als Flipper-Zero-App** — gedacht, um **deine
eigenen Geräte** zu testen: Fernseher & AV-Technik (IR), eigene Funk-
Fernbedienungen (Sub-GHz), kontaktlose Karten/Tags (NFC, RFID, iButton),
Elektronik & Busse (GPIO, UART, I²C, SPI) und deinen eigenen PC (BadUSB, U2F).

> Läuft auf der **offiziellen Firmware**, **ohne jede Zusatz-Hardware** — nur
> mit dem, was im Flipper Zero steckt.

---

## Inhalt

- [Was es kann (und was nicht)](#was-es-kann-und-was-nicht)
- [Die fertige `.fap` bekommen](#die-fertige-fap-bekommen)
- [Module im Überblick](#module-im-überblick)
- [Projektstruktur](#projektstruktur)
- [Weiterführende Doku](#weiterführende-doku)
- [Rechtlicher Hinweis](#rechtlicher-hinweis)

---

## Was es kann (und was nicht)

Der Flipper Zero hat **kein eigenes WLAN/Ethernet**. Netzwerk-/WLAN-Tests
(Portscan, WLAN-Audit) gehen nur mit der separaten ESP32-Erweiterung — die ist
in diesem Projekt **bewusst nicht** vorgesehen. Alles hier läuft über die
sechs Onboard-Subsysteme:

| Dein Ziel | Weg im Tool | Hardware |
|---|---|---|
| TV / Soundbar / Beamer testen | Modul **IR** | 3 IR-LEDs + Empfänger |
| Eigene 433/868-MHz-Fernbedienungen | Modul **Sub-GHz** | CC1101 |
| Eigene kontaktlose Karten auslesen | Modul **NFC** / **RFID** | 13,56 MHz / 125 kHz |
| Eigene Kontaktschlüssel | Modul **iButton** | 1-Wire |
| Elektronik, Sensoren, Busse | **GPIO / UART / I²C / SPI** | 18 GPIO-Pins |
| Eigenen PC automatisiert testen | **BadUSB / U2F** | USB-HID |

**Geht grundsätzlich nicht** (Hardware-Grenze, keine Software ändert das):
Bankkarten (EMV) klonen, moderne Autos mit Rolling-Code öffnen, WPA3 knacken.

Siehe Details in [`docs/MODULES.md`](docs/MODULES.md).

---

## Die fertige `.fap` bekommen

Du hast **drei Wege**. Der erste braucht auf deinem Rechner gar nichts.

### Weg A — automatisch über GitHub (nur herunterladen)

1. Lege das Repo auf deinem GitHub-Account an und pushe es (siehe unten).
2. Der mitgelieferte Workflow [`.github/workflows/build.yml`](.github/workflows/build.yml)
   baut die `.fap` automatisch.
3. **Download:** GitHub → Reiter **Actions** → letzter Lauf → unten
   **Artifacts → `devicetest_lab-fap`**.
4. Für eine feste Release-Datei: einen Tag pushen (`git tag v0.1 && git push --tags`)
   → die `.fap` hängt dann unter **Releases**.

```bash
# Repo zu deinem GitHub pushen (einmalig)
git add -A
git commit -m "DeviceTest Lab: Grundgeruest + CI"
git branch -M main
git remote add origin https://github.com/<DEIN-NAME>/devicetest_lab.git
git push -u origin main
```

### Weg B — lokal selbst bauen (ein Befehl)

```bash
pip install ufbt
ufbt            # baut dist/devicetest_lab.fap
ufbt launch     # baut + startet direkt auf dem angeschlossenen Flipper
```

### Weg C — fertige `.fap` von Hand aufspielen

Die gebaute Datei `dist/devicetest_lab.fap` auf die SD-Karte nach
`/ext/apps/Tools/` kopieren (qFlipper oder Kartenleser). Auf dem Flipper
erscheint sie unter **Apps → Tools → DeviceTest Lab**.

> Hinweis: Eine vorkompilierte `.fap` liegt dem Repo **nicht** bei — Binaries
> gehören nicht in die Versionskontrolle, und sie muss zur installierten
> Firmware-Version passen. Weg A/B erzeugen immer die passende.

Ausführliche Bauanleitung: [`docs/BUILD.md`](docs/BUILD.md).

---

## Module im Überblick

15 Module, gruppiert. Das Grundgerüst ist vollständig: Jedes Modul ist im Menü
erreichbar und zeigt seinen Zweck. Die eigentliche Funk-/Hardware-Logik wird
Modul für Modul eingebaut (empfohlene Reihenfolge in `docs/MODULES.md`).

| Gruppe | Module |
|---|---|
| Funk / RF | IR · Sub-GHz |
| Kontaktlos | NFC · RFID 125 kHz · iButton |
| Kabel / PC / HW | GPIO · UART · I²C · SPI · BadUSB · U2F |
| Mess / Hilfe | Sensoren · Hardware-Selbsttest · Log/Historie · Info |

---

## Projektstruktur

```
devicetest_lab/
├── application.fam              App-Manifest (Name, Entry-Point, benötigte Records)
├── devicetest_lab.h/.c          App-Objekt, ViewDispatcher + SceneManager, Entry-Point
├── scenes/
│   ├── devicetest_scene_config.h   ← ZENTRALE Modul-Liste (X-Macro)
│   ├── devicetest_scene.h/.c       automatisch erzeugte Handler-Tabellen
│   ├── devicetest_scene_main_menu.c  Hauptmenü
│   └── devicetest_scene_<modul>.c    je ein Modul (ir, nfc, subghz, …)
├── helpers/
│   └── sd_layout.h              zentrale SD-Kartenpfade für Dumps/Logs
├── assets/                      (optional) Icon
├── .github/workflows/build.yml  automatischer Build
└── docs/                        ausführliche Dokumentation
```

Wie das zusammenspielt: [`docs/ARCHITECTURE.md`](docs/ARCHITECTURE.md).
Ein neues Modul hinzufügen (= 1 Zeile + 1 Datei): [`docs/EXTENDING.md`](docs/EXTENDING.md).

---

## Weiterführende Doku

| Datei | Inhalt |
|---|---|
| [`docs/ARCHITECTURE.md`](docs/ARCHITECTURE.md) | Wie App, ViewDispatcher, SceneManager und das X-Macro-Pattern zusammenhängen |
| [`docs/MODULES.md`](docs/MODULES.md) | Jedes Modul: Zweck, genutzte Flipper-API, Umsetzungs-Reihenfolge |
| [`docs/BUILD.md`](docs/BUILD.md) | Bauen via GitHub Actions und lokal mit ufbt, Installation, Debugging |
| [`docs/EXTENDING.md`](docs/EXTENDING.md) | Schritt-für-Schritt: neues Modul, SD-Speichern, eigene Views |
| [`docs/LEGAL.md`](docs/LEGAL.md) | Eigene Geräte, erlaubte Funkbänder, Verantwortung |

---

## Rechtlicher Hinweis

Dieses Werkzeug ist ausschließlich für **eigene Geräte** und zum Lernen
gedacht. Funk-Module (besonders Sub-GHz) nur in den **bei dir rechtlich
erlaubten Frequenzbändern und Sendeleistungen** verwenden. Zugangs-, Karten-
und HID-Module nur an **deiner eigenen** Hardware. Du bist für die Einhaltung
der Gesetze an deinem Ort selbst verantwortlich. Details:
[`docs/LEGAL.md`](docs/LEGAL.md).
