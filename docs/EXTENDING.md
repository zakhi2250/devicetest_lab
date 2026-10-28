# Erweitern — neues Modul in 3 Schritten

Dank des X-Macro-Patterns ist ein neues Modul minimal. Beispiel: ein Modul
„Beispiel" (`example`).

## Schritt 1 — eine Zeile in die Modul-Liste

`scenes/devicetest_scene_config.h`:

```c
ADD_SCENE(devicetest, example, Example)
```

Daraus entstehen automatisch das Enum `DeviceTestSceneExample` und die
Prototypen.

## Schritt 2 — die Modul-Datei anlegen

`scenes/devicetest_scene_example.c`:

```c
#include "../devicetest_lab.h"

void devicetest_scene_example_on_enter(void* context) {
    DeviceTestApp* app = context;
    devicetest_show_placeholder(app, "Beispiel", "Hallo Welt.");
    // Stattdessen eigene View befüllen (Submenu/VariableItemList/TextBox) …
}

bool devicetest_scene_example_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return false; // Zurück behandelt der SceneManager zentral
}

void devicetest_scene_example_on_exit(void* context) {
    UNUSED(context);
    // Hardware/Worker hier stoppen, falls in _on_enter gestartet
}
```

## Schritt 3 — im Hauptmenü verlinken

`scenes/devicetest_scene_main_menu.c`, in `..._on_enter`:

```c
submenu_add_item(menu, "Beispiel", DeviceTestSceneExample,
                 devicetest_main_menu_callback, app);
```

Fertig. `ufbt` neu bauen — das Modul ist im Menü.

---

## Häufige Bausteine

### Auf SD speichern

```c
#include "../helpers/sd_layout.h"
#include <storage/storage.h>

Storage* storage = furi_record_open(RECORD_STORAGE);
storage_common_mkdir(storage, DEVICETEST_DIR);        // Basisordner
storage_common_mkdir(storage, DEVICETEST_DIR_LOGS);   // Unterordner

File* file = storage_file_alloc(storage);
if(storage_file_open(file, DEVICETEST_DIR_LOGS "/test.txt",
                     FSAM_WRITE, FSOM_CREATE_ALWAYS)) {
    const char* line = "Ergebnis\n";
    storage_file_write(file, line, strlen(line));
}
storage_file_close(file);
storage_file_free(file);
furi_record_close(RECORD_STORAGE);
```

### Scrollbaren Text (Log/Dump) anzeigen — TextBox-View

```c
text_box_reset(app->text_box);
text_box_set_text(app->text_box, furi_string_get_cstr(mein_furi_string));
view_dispatcher_switch_to_view(app->view_dispatcher, DeviceTestViewTextBox);
```

### Einstellungen pro Modul — VariableItemList-View

Für Dinge wie Baudrate, Frequenz, Protokoll: `variable_item_list_add(...)`
nutzen und auf `DeviceTestViewVarItemList` umschalten.

### Eine Hardware/Worker im Modul nutzen

1. In `application.fam` den Record unter `requires` ergänzen (z. B. `"subghz"`).
2. In `_on_enter` mit `furi_record_open(...)` öffnen bzw. Worker starten.
3. In `_on_exit` wieder stoppen/schließen — **immer sauber aufräumen**, sonst
   bleibt die Hardware belegt.

### Rückmeldung geben (LED/Vibro/Ton)

```c
notification_message(app->notifications, &sequence_success);
notification_message(app->notifications, &sequence_error);
```

---

## Konventionen

- Ein Modul = eine Scene-Datei, Name `devicetest_scene_<name>.c`.
- Schwere Subsystem-Logik gehört in `modules/<name>.c` + `.h`; die Scene ruft
  sie nur auf (hält die GUI-Schicht dünn).
- Geteilte Pfade in `helpers/sd_layout.h`, nicht hartkodieren.
- Nach `_on_enter`-Allokationen immer passendes `_on_exit`-Aufräumen.
