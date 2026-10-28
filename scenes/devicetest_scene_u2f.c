/**
 * Modul: U2F — Flipper als FIDO-U2F-Sicherheitsschluessel.
 *
 * Geplante Funktion (TODO): U2F-Token bereitstellen, Anmeldung an eigenen
 * Konten/Diensten testen, Zaehler/Status anzeigen.
 * API: furi_hal_usb (u2f), u2f_data.
 */
#include "../devicetest_lab.h"

void devicetest_scene_u2f_on_enter(void* context) {
    devicetest_show_placeholder(
        context,
        "U2F Key",
        "2-Faktor-Hardwareschluessel\nfuer eigene Logins testen.\n\n"
        "Geplant:\n"
        "- Als U2F anmelden\n"
        "- Anmeldung bestaetigen\n"
        "- Status / Zaehler\n\n"
        "Status: Geruest.");
}

bool devicetest_scene_u2f_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return false;
}

void devicetest_scene_u2f_on_exit(void* context) {
    UNUSED(context);
}
