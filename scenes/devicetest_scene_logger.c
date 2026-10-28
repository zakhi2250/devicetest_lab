/**
 * Modul: Log / Historie — Ergebnisse zentral auf SD.
 *
 * Geplante Funktion (TODO): Test-Historie anzeigen und als Textlog unter
 * /ext/apps_data/devicetest_lab/logs/ fuehren; Dumps der Module verlinken.
 * API: storage, furi_string, text_box. Siehe helpers/sd_layout.h.
 */
#include "../devicetest_lab.h"
#include "../helpers/sd_layout.h"

void devicetest_scene_logger_on_enter(void* context) {
    devicetest_show_placeholder(
        context,
        "Log / Historie",
        "Alle Ergebnisse an einem Ort.\n\n"
        "Pfad auf SD:\n" DEVICETEST_DIR "/\n\n"
        "Geplant:\n"
        "- Test-Historie\n"
        "- Dumps auflisten\n\n"
        "Status: Geruest.");
}

bool devicetest_scene_logger_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return false;
}

void devicetest_scene_logger_on_exit(void* context) {
    UNUSED(context);
}
