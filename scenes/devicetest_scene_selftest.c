/**
 * Modul: Hardware-Selbsttest — pruefen, ob der Flipper selbst ok ist.
 *
 * Geplante Funktion (TODO): LED/Vibro/Display/Speaker testen, Akkustand &
 * Temperatur, SD erkannt?, CC1101/NFC-Chip antworten?
 * API: notification, furi_hal_power, furi_hal_speaker, storage.
 */
#include "../devicetest_lab.h"

void devicetest_scene_selftest_on_enter(void* context) {
    devicetest_show_placeholder(
        context,
        "Hardware-Selbsttest",
        "Den Flipper selbst pruefen.\n\n"
        "Geplant:\n"
        "- LED/Vibro/Ton\n"
        "- Akku & Temperatur\n"
        "- SD / Funk-Chips\n\n"
        "Status: Geruest.");
}

bool devicetest_scene_selftest_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return false;
}

void devicetest_scene_selftest_on_exit(void* context) {
    UNUSED(context);
}
