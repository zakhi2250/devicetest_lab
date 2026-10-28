/**
 * Modul: Info & Rechtlicher Hinweis.
 */
#include "../devicetest_lab.h"

void devicetest_scene_about_on_enter(void* context) {
    devicetest_show_placeholder(
        context,
        "Info & Recht",
        "DeviceTest Lab v0.1\n\n"
        "Modulares Test-Labor fuer\nDEINE EIGENEN Geraete.\n\n"
        "Nur an eigener Hardware\nnutzen. Funk nur in lokal\nerlaubten Baendern.\n\n"
        "Du bist fuer die Nutzung\nselbst verantwortlich.");
}

bool devicetest_scene_about_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return false;
}

void devicetest_scene_about_on_exit(void* context) {
    UNUSED(context);
}
