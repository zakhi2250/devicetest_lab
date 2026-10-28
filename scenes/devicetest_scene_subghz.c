/**
 * Modul: Sub-GHz — eigene 433/868-MHz-Funkgeraete testen.
 *
 * Geplante Funktion (TODO): Frequenz-Analyzer (RSSI), eigene Fernbedienungen
 * lesen und als *.sub speichern, erneut senden. NUR in lokal erlaubten
 * Baendern — Frequenz-Whitelist im Modul erzwingen (siehe docs/LEGAL.md).
 * API: subghz_devices, subghz_worker, furi_hal_subghz.
 */
#include "../devicetest_lab.h"

void devicetest_scene_subghz_on_enter(void* context) {
    devicetest_show_placeholder(
        context,
        "Sub-GHz Funk",
        "Eigene Funkfernbedienungen\n& Sensoren (433/868 MHz).\n\n"
        "Geplant:\n"
        "- Frequenz-Analyzer\n"
        "- Lesen -> .sub\n"
        "- Erneut senden\n\n"
        "Nur erlaubte Baender!\n"
        "Status: Geruest.");
}

bool devicetest_scene_subghz_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return false;
}

void devicetest_scene_subghz_on_exit(void* context) {
    UNUSED(context);
}
