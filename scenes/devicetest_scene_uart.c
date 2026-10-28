/**
 * Modul: UART-Konsole — serielle Schnittstelle eigener Geraete.
 *
 * Geplante Funktion (TODO): TX/RX an GPIO 13/14, Baudrate waehlbar,
 * eingehende Konsole scrollbar anzeigen (Router, SBCs, Boards),
 * optional Mitschnitt auf SD. API: furi_hal_serial, furi_stream_buffer.
 */
#include "../devicetest_lab.h"

void devicetest_scene_uart_on_enter(void* context) {
    devicetest_show_placeholder(
        context,
        "UART Konsole",
        "Serielle Konsole an\neigene Geraete haengen.\n\n"
        "Geplant:\n"
        "- Baudrate waehlen\n"
        "- RX live anzeigen\n"
        "- Mitschnitt -> SD\n\n"
        "Status: Geruest.");
}

bool devicetest_scene_uart_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return false;
}

void devicetest_scene_uart_on_exit(void* context) {
    UNUSED(context);
}
