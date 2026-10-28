/**
 * Modul: BadUSB — eigene HID-Testskripte am eigenen PC ausfuehren.
 *
 * Geplante Funktion (TODO): *.txt (Ducky-Syntax) von SD waehlen, Tastatur-
 * layout setzen, Skript als USB-HID-Tastatur abspielen. Ausschliesslich
 * fuer eigene Automatisierung/Tests. API: furi_hal_usb_hid, bad_usb_script.
 */
#include "../devicetest_lab.h"

void devicetest_scene_badusb_on_enter(void* context) {
    devicetest_show_placeholder(
        context,
        "BadUSB (HID)",
        "Eigene Tastatur-Skripte\nam eigenen PC testen.\n\n"
        "Geplant:\n"
        "- .txt von SD waehlen\n"
        "- Layout setzen\n"
        "- Skript abspielen\n\n"
        "Status: Geruest.");
}

bool devicetest_scene_badusb_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return false;
}

void devicetest_scene_badusb_on_exit(void* context) {
    UNUSED(context);
}
