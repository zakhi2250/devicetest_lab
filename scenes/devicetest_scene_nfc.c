/**
 * Modul: NFC 13,56 MHz — eigene Karten/Tags auslesen.
 *
 * Geplante Funktion (TODO): ISO14443-A/B lesen, UID + Typ anzeigen,
 * MIFARE-Classic-Schluessel per Dictionary versuchen, Dump als *.nfc
 * auf SD, eigene Karte emulieren.
 * API: nfc, nfc_device, nfc_poller, nfc_dict.
 */
#include "../devicetest_lab.h"

void devicetest_scene_nfc_on_enter(void* context) {
    devicetest_show_placeholder(
        context,
        "NFC 13.56 MHz",
        "Eigene kontaktlose Karten\n& Tags auslesen.\n\n"
        "Geplant:\n"
        "- UID / Typ anzeigen\n"
        "- Dump -> .nfc\n"
        "- Eigene Karte emulieren\n\n"
        "Status: Geruest.");
}

bool devicetest_scene_nfc_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return false;
}

void devicetest_scene_nfc_on_exit(void* context) {
    UNUSED(context);
}
