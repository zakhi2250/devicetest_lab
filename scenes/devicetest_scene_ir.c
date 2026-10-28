/**
 * Modul: Infrarot — TV & AV-Geraete testen.
 *
 * Geplante Funktion (TODO): IR-Signale vom Empfaenger (TSOP) anlernen,
 * als *.ir auf SD speichern, ueber die 3 IR-LEDs senden; Universal-Remote
 * (Power/Vol/Source) gegen eigene Geraete durchprobieren.
 * API: infrared_worker_rx/tx, infrared_signal, dialogs/storage.
 */
#include "../devicetest_lab.h"

void devicetest_scene_ir_on_enter(void* context) {
    devicetest_show_placeholder(
        context,
        "IR / TV & AV",
        "Steuert TV, Soundbar, Beamer.\n\n"
        "Geplant:\n"
        "- Fernbedienung anlernen\n"
        "- Codes senden\n"
        "- Universal-Remote\n"
        "- Speichern als .ir\n\n"
        "Status: Geruest.");
}

bool devicetest_scene_ir_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return false; // Back wird zentral vom SceneManager behandelt
}

void devicetest_scene_ir_on_exit(void* context) {
    UNUSED(context);
}
