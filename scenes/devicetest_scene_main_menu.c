/**
 * Hauptmenue — listet alle Module auf und springt ins gewaehlte.
 *
 * Trick: Der Submenu-Index IST die Ziel-Scene-ID (DeviceTestScene<Id>).
 * Dadurch ist die Weiterleitung ein Einzeiler und neue Module brauchen
 * hier nur eine zusaetzliche submenu_add_item-Zeile.
 */
#include "../devicetest_lab.h"

static void devicetest_main_menu_callback(void* context, uint32_t index) {
    DeviceTestApp* app = context;
    // index == Ziel-Scene-ID -> als custom event weiterreichen
    view_dispatcher_send_custom_event(app->view_dispatcher, index);
}

void devicetest_scene_main_menu_on_enter(void* context) {
    DeviceTestApp* app = context;
    Submenu* menu = app->submenu;

    submenu_reset(menu);
    submenu_set_header(menu, "DeviceTest Lab");

    // --- Funk / RF ---
    submenu_add_item(menu, "IR / TV & AV", DeviceTestSceneIr, devicetest_main_menu_callback, app);
    submenu_add_item(menu, "Sub-GHz Funk", DeviceTestSceneSubghz, devicetest_main_menu_callback, app);
    // --- Kontaktlos ---
    submenu_add_item(menu, "NFC 13.56 MHz", DeviceTestSceneNfc, devicetest_main_menu_callback, app);
    submenu_add_item(menu, "RFID 125 kHz", DeviceTestSceneRfid, devicetest_main_menu_callback, app);
    submenu_add_item(menu, "iButton 1-Wire", DeviceTestSceneIbutton, devicetest_main_menu_callback, app);
    // --- Kabel / PC / Hardware ---
    submenu_add_item(menu, "GPIO Pins", DeviceTestSceneGpio, devicetest_main_menu_callback, app);
    submenu_add_item(menu, "UART Konsole", DeviceTestSceneUart, devicetest_main_menu_callback, app);
    submenu_add_item(menu, "I2C Scanner", DeviceTestSceneI2c, devicetest_main_menu_callback, app);
    submenu_add_item(menu, "SPI Test", DeviceTestSceneSpi, devicetest_main_menu_callback, app);
    submenu_add_item(menu, "BadUSB (HID)", DeviceTestSceneBadusb, devicetest_main_menu_callback, app);
    submenu_add_item(menu, "U2F Key", DeviceTestSceneU2f, devicetest_main_menu_callback, app);
    // --- Mess- / Hilfsmodule ---
    submenu_add_item(menu, "Sensoren", DeviceTestSceneSensors, devicetest_main_menu_callback, app);
    submenu_add_item(menu, "Hardware-Selbsttest", DeviceTestSceneSelftest, devicetest_main_menu_callback, app);
    submenu_add_item(menu, "Log / Historie", DeviceTestSceneLogger, devicetest_main_menu_callback, app);
    submenu_add_item(menu, "Info & Recht", DeviceTestSceneAbout, devicetest_main_menu_callback, app);

    // Zuletzt gewaehlte Position wiederherstellen
    submenu_set_selected_item(
        menu, scene_manager_get_scene_state(app->scene_manager, DeviceTestSceneMainMenu));

    view_dispatcher_switch_to_view(app->view_dispatcher, DeviceTestViewSubmenu);
}

bool devicetest_scene_main_menu_on_event(void* context, SceneManagerEvent event) {
    DeviceTestApp* app = context;
    bool consumed = false;

    if(event.type == SceneManagerEventTypeCustom) {
        // Auswahl merken, damit die Liste nach dem Zurueck an gleicher Stelle steht
        scene_manager_set_scene_state(app->scene_manager, DeviceTestSceneMainMenu, event.event);
        scene_manager_next_scene(app->scene_manager, event.event);
        consumed = true;
    }
    return consumed;
}

void devicetest_scene_main_menu_on_exit(void* context) {
    DeviceTestApp* app = context;
    submenu_reset(app->submenu);
}
