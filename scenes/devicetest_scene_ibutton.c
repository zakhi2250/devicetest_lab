/**
 * Modul: iButton 1-Wire — eigene Kontaktschluessel.
 *
 * Geplante Funktion (TODO): Dallas/Cyfral/Metakom lesen, UID anzeigen,
 * auf beschreibbaren Rohling schreiben, emulieren, als *.ibtn speichern.
 * API: ibutton_worker, ibutton_protocols.
 */
#include "../devicetest_lab.h"

void devicetest_scene_ibutton_on_enter(void* context) {
    devicetest_show_placeholder(
        context,
        "iButton 1-Wire",
        "Kontakt-Schluessel\n(Dallas u.a.).\n\n"
        "Geplant:\n"
        "- Lesen + UID\n"
        "- Emulieren\n"
        "- Schreiben / .ibtn\n\n"
        "Status: Geruest.");
}

bool devicetest_scene_ibutton_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return false;
}

void devicetest_scene_ibutton_on_exit(void* context) {
    UNUSED(context);
}
