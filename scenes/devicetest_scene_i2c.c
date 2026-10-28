/**
 * Modul: I2C-Scanner — Bus an GPIO absuchen.
 *
 * Geplante Funktion (TODO): I2C-Adressraum 0x08..0x77 durchprobieren,
 * gefundene Geraete auflisten, einzelne Register lesen.
 * API: furi_hal_i2c (external bus: C0/C1 bzw. Pins 15/16).
 */
#include "../devicetest_lab.h"

void devicetest_scene_i2c_on_enter(void* context) {
    devicetest_show_placeholder(
        context,
        "I2C Scanner",
        "Angeschlossene I2C-Chips\nfinden (Sensoren, Displays).\n\n"
        "Geplant:\n"
        "- Adressen scannen\n"
        "- Geraete auflisten\n"
        "- Register lesen\n\n"
        "Status: Geruest.");
}

bool devicetest_scene_i2c_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return false;
}

void devicetest_scene_i2c_on_exit(void* context) {
    UNUSED(context);
}
