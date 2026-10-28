/**
 * Modul: GPIO — die 18 Pins testen.
 *
 * Geplante Funktion (TODO): Pin als Ein-/Ausgang schalten, Logikpegel
 * live anzeigen, 3,3V/5V-Ausgang aktivieren, einfacher Logik-Monitor.
 * API: furi_hal_gpio, furi_hal_power (5V am Pin 1).
 */
#include "../devicetest_lab.h"

void devicetest_scene_gpio_on_enter(void* context) {
    devicetest_show_placeholder(
        context,
        "GPIO Pins",
        "18 Pins (3,3V, 5V-tolerant).\n\n"
        "Geplant:\n"
        "- Pegel lesen (live)\n"
        "- Pin schalten\n"
        "- 3,3V/5V-Ausgang\n\n"
        "Status: Geruest.");
}

bool devicetest_scene_gpio_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return false;
}

void devicetest_scene_gpio_on_exit(void* context) {
    UNUSED(context);
}
