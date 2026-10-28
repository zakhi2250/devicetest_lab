/**
 * Modul: SPI-Test — einfache SPI-Transfers.
 *
 * Geplante Funktion (TODO): SPI-Bytes senden/empfangen, z.B. JEDEC-ID
 * eines SPI-Flash auslesen, um Verkabelung/Chip zu pruefen.
 * API: furi_hal_spi (external bus).
 */
#include "../devicetest_lab.h"

void devicetest_scene_spi_on_enter(void* context) {
    devicetest_show_placeholder(
        context,
        "SPI Test",
        "SPI-Bauteile pruefen\n(z.B. Flash-Chips).\n\n"
        "Geplant:\n"
        "- Byte-Transfer\n"
        "- JEDEC-ID lesen\n"
        "- Verkabelung testen\n\n"
        "Status: Geruest.");
}

bool devicetest_scene_spi_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return false;
}

void devicetest_scene_spi_on_exit(void* context) {
    UNUSED(context);
}
