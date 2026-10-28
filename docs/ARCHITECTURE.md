# Architektur

So ist die App aufgebaut — bewusst nach dem Muster der offiziellen
Flipper-Firmware-Apps, damit sie vertraut und erweiterbar bleibt.

## Die zwei zentralen Bausteine

```
        ┌─────────────────────────────────────────────┐
        │                 DeviceTestApp                │   (devicetest_lab.h)
        │  gui, notifications, geteilte Views …        │
        └───────────────┬───────────────┬─────────────┘
                        │               │
             ┌──────────▼───────┐  ┌────▼─────────────┐
             │  ViewDispatcher  │  │  SceneManager    │
             │  zeigt die aktive│  │  Stack der Module│
             │  View, verteilt  │  │  (Scenes), kennt │
             │  Tasten-Events   │  │  Vor/Zurück      │
             └──────────────────┘  └──────────────────┘
```

- **ViewDispatcher**: hält mehrere *Views* (Submenu, Widget, VariableItemList,
  TextBox) und zeigt immer genau eine an. Tasten-Eingaben laufen durch ihn.
- **SceneManager**: verwaltet die *Scenes* als Stapel. Ein Modul = eine Scene.
  „Weiter" legt eine Scene oben drauf, „Zurück" nimmt sie wieder weg.

Beide werden in `devicetest_lab.c` in `devicetest_app_alloc()` erzeugt und über
zwei Callbacks verbunden:

- `devicetest_custom_event_callback` → `scene_manager_handle_custom_event`
  (ein Menüklick wird zum Szenenwechsel)
- `devicetest_back_event_callback` → `scene_manager_handle_back_event`
  (die Zurück-Taste nimmt eine Scene vom Stapel; ist der Stapel leer, endet die App)

## Views vs. Scenes

- Eine **View** ist ein GUI-Baustein (wie sieht der Bildschirm aus). Wir teilen
  uns vier Standard-Views, statt pro Modul eine eigene zu bauen — das spart
  Code und Speicher.
- Eine **Scene** ist ein Zustand/Schritt (welches Modul ist gerade aktiv). Jede
  Scene *befüllt* beim Betreten eine passende View.

Jede Scene hat drei Funktionen:

| Funktion | Wird aufgerufen … | Typische Aufgabe |
|---|---|---|
| `_on_enter` | beim Betreten | View befüllen, Hardware starten |
| `_on_event` | bei Eingaben/Ticks/Custom-Events | reagieren, Szenenwechsel auslösen |
| `_on_exit` | beim Verlassen | aufräumen, Hardware stoppen |

## Das X-Macro-Pattern (Herzstück der Erweiterbarkeit)

Alle Module stehen **an genau einer Stelle**: `scenes/devicetest_scene_config.h`.

```c
ADD_SCENE(devicetest, main_menu, MainMenu)
ADD_SCENE(devicetest, ir,        Ir)
ADD_SCENE(devicetest, nfc,       Nfc)
...
```

Diese Datei wird mehrfach mit jeweils anderer `ADD_SCENE`-Definition
eingebunden (`#include`) und erzeugt daraus automatisch:

1. **das Enum** `DeviceTestScene<Id>` (in `devicetest_scene.h`)
2. **die Funktions-Prototypen** `devicetest_scene_<name>_on_enter/_event/_exit`
3. **die drei Handler-Tabellen** (in `devicetest_scene.c`), die der
   SceneManager nutzt, um anhand der Enum-ID die richtige Funktion zu finden.

**Folge:** Ein neues Modul = **eine Zeile** in der Config + **eine** Datei
`devicetest_scene_<name>.c`. Keine Tabellen, keine Enums von Hand pflegen.
Schritt-für-Schritt in [`EXTENDING.md`](EXTENDING.md).

## Navigationsfluss (Beispiel)

```
Start → MainMenu (Submenu-View)
        │ Klick "NFC"  → custom event = DeviceTestSceneNfc
        ▼
     Nfc-Scene (Widget-View)
        │ Zurück-Taste → SceneManager pop
        ▼
     MainMenu (an gleicher Position, weil der Index gemerkt wird)
        │ Zurück-Taste → Stapel leer → App endet
```

Der kleine Trick im Hauptmenü: Der Submenu-*Index* ist direkt die Ziel-Scene-ID.
Dadurch ist die Weiterleitung ein Einzeiler
(`scene_manager_next_scene(app->scene_manager, event.event)`).

## Speicher & Records

`application.fam` listet unter `requires` die System-*Records*, die beim Start
geöffnet werden (aktuell `gui`, `storage`, `notification`). Bekommt ein Modul
echte Logik, die z. B. den NFC- oder Sub-GHz-Chip braucht, wird der passende
Record dort ergänzt und im Modul per `furi_record_open()` geöffnet.
