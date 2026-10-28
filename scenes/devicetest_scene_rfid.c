/**
 * Modul: RFID 125 kHz — eigene Low-Frequency-Tags.
 *
 * Geplante Funktion (TODO): EM4100 / HID Prox lesen, UID anzeigen,
 * auf leere T5577-Karte schreiben, als *.rfid speichern.
 * API: lfrfid_worker, protocol_dict.
 */
#include "../devicetest_lab.h"

void devicetest_scene_rfid_on_enter(void* context) {
    devicetest_show_placeholder(
        context,
        "RFID 125 kHz",
        "Aeltere Zugangs-Tags\n(EM4100, HID Prox).\n\n"
        "Geplant:\n"
        "- Lesen + UID\n"
        "- Auf T5577 schreiben\n"
        "- Speichern .rfid\n\n"
        "Status: Geruest.");
}

bool devicetest_scene_rfid_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return false;
}

void devicetest_scene_rfid_on_exit(void* context) {
    UNUSED(context);
}
