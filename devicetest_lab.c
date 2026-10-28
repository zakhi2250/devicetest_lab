/**
 * DeviceTest Lab — Entry-Point und App-Lebenszyklus.
 *
 * Aufbau nach dem offiziellen Flipper-Muster:
 *   ViewDispatcher  -> rendert/verteilt Eingaben an die aktive View
 *   SceneManager    -> haelt den Navigations-Stack der Module (Scenes)
 *
 * Der Datenfluss:
 *   Submenu-Klick -> custom event -> SceneManager -> naechste Scene
 *   Back-Taste    -> navigation callback -> SceneManager -> Scene zurueck
 */
#include "devicetest_lab.h"

// ----------------------------------------------------------------------------
// Callbacks, die den ViewDispatcher mit dem SceneManager verbinden
// ----------------------------------------------------------------------------

static bool devicetest_custom_event_callback(void* context, uint32_t event) {
    furi_assert(context);
    DeviceTestApp* app = context;
    return scene_manager_handle_custom_event(app->scene_manager, event);
}

static bool devicetest_back_event_callback(void* context) {
    furi_assert(context);
    DeviceTestApp* app = context;
    return scene_manager_handle_back_event(app->scene_manager);
}

// ----------------------------------------------------------------------------
// Geteilter GUI-Helfer
// ----------------------------------------------------------------------------

void devicetest_show_placeholder(DeviceTestApp* app, const char* title, const char* body) {
    furi_assert(app);
    // Titel fett oben (\e# ... \e#), Rumpf darunter — als ein Scroll-Block.
    widget_reset(app->widget);
    FuriString* text = furi_string_alloc();
    furi_string_printf(text, "\e#%s\e#\n%s", title, body);
    widget_add_text_scroll_element(app->widget, 0, 0, 128, 64, furi_string_get_cstr(text));
    furi_string_free(text);
    view_dispatcher_switch_to_view(app->view_dispatcher, DeviceTestViewWidget);
}

// ----------------------------------------------------------------------------
// App-Allokation / Freigabe
// ----------------------------------------------------------------------------

static DeviceTestApp* devicetest_app_alloc(void) {
    DeviceTestApp* app = malloc(sizeof(DeviceTestApp));

    app->gui = furi_record_open(RECORD_GUI);
    app->notifications = furi_record_open(RECORD_NOTIFICATION);

    app->view_dispatcher = view_dispatcher_alloc();
    app->scene_manager = scene_manager_alloc(&devicetest_scene_handlers, app);

    view_dispatcher_set_event_callback_context(app->view_dispatcher, app);
    view_dispatcher_set_custom_event_callback(
        app->view_dispatcher, devicetest_custom_event_callback);
    view_dispatcher_set_navigation_event_callback(
        app->view_dispatcher, devicetest_back_event_callback);

    // Views anlegen und registrieren
    app->submenu = submenu_alloc();
    view_dispatcher_add_view(
        app->view_dispatcher, DeviceTestViewSubmenu, submenu_get_view(app->submenu));

    app->widget = widget_alloc();
    view_dispatcher_add_view(
        app->view_dispatcher, DeviceTestViewWidget, widget_get_view(app->widget));

    app->var_item_list = variable_item_list_alloc();
    view_dispatcher_add_view(
        app->view_dispatcher,
        DeviceTestViewVarItemList,
        variable_item_list_get_view(app->var_item_list));

    app->text_box = text_box_alloc();
    view_dispatcher_add_view(
        app->view_dispatcher, DeviceTestViewTextBox, text_box_get_view(app->text_box));

    view_dispatcher_attach_to_gui(
        app->view_dispatcher, app->gui, ViewDispatcherTypeFullscreen);

    return app;
}

static void devicetest_app_free(DeviceTestApp* app) {
    furi_assert(app);

    view_dispatcher_remove_view(app->view_dispatcher, DeviceTestViewSubmenu);
    view_dispatcher_remove_view(app->view_dispatcher, DeviceTestViewWidget);
    view_dispatcher_remove_view(app->view_dispatcher, DeviceTestViewVarItemList);
    view_dispatcher_remove_view(app->view_dispatcher, DeviceTestViewTextBox);

    submenu_free(app->submenu);
    widget_free(app->widget);
    variable_item_list_free(app->var_item_list);
    text_box_free(app->text_box);

    scene_manager_free(app->scene_manager);
    view_dispatcher_free(app->view_dispatcher);

    furi_record_close(RECORD_NOTIFICATION);
    furi_record_close(RECORD_GUI);

    free(app);
}

// ----------------------------------------------------------------------------
// Entry-Point (muss zu entry_point in application.fam passen)
// ----------------------------------------------------------------------------

int32_t devicetest_lab_app(void* p) {
    UNUSED(p);
    DeviceTestApp* app = devicetest_app_alloc();

    // Beim Start ins Hauptmenue
    scene_manager_next_scene(app->scene_manager, DeviceTestSceneMainMenu);

    view_dispatcher_run(app->view_dispatcher);

    devicetest_app_free(app);
    return 0;
}
