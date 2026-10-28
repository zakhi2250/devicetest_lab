/**
 * Modul: Sensoren — 1-Wire/Analog ueber GPIO auslesen.
 *
 * Geplante Funktion (TODO): DS18B20 (Temperatur) oder DHT ueber 1-Wire/GPIO
 * lesen, Werte live anzeigen und optional mitschreiben.
 * API: furi_hal_gpio, onewire host, furi_hal_adc.
 */
#include "../devicetest_lab.h"

void devicetest_scene_sensors_on_enter(void* context) {
    devicetest_show_placeholder(
        context,
        "Sensoren",
        "Temperatur/Feuchte u.a.\nueber GPIO messen.\n\n"
        "Geplant:\n"
        "- DS18B20 / DHT lesen\n"
        "- Werte live\n"
        "- Mitschnitt -> SD\n\n"
        "Status: Geruest.");
}

bool devicetest_scene_sensors_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return false;
}

void devicetest_scene_sensors_on_exit(void* context) {
    UNUSED(context);
}
