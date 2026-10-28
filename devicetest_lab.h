/**
 * DeviceTest Lab — zentrale App-Struktur und geteilter State.
 *
 * Diese Datei definiert das App-Objekt, das jede Scene (jedes Modul) als
 * Kontext bekommt. Hier liegen die GUI-Views, die alle Module gemeinsam
 * nutzen. Modul-spezifischer State kommt entweder hier als eigener Zeiger
 * dazu oder — sauberer — in ein eigenes modules/<name>.h.
 */
#pragma once

#include <furi.h>
#include <gui/gui.h>
#include <gui/view_dispatcher.h>
#include <gui/scene_manager.h>
#include <gui/modules/submenu.h>
#include <gui/modules/widget.h>
#include <gui/modules/variable_item_list.h>
#include <gui/modules/text_box.h>
#include <notification/notification_messages.h>

#include "scenes/devicetest_scene.h"

/** View-IDs: pro wiederverwendbarem GUI-Baustein eine ID. */
typedef enum {
    DeviceTestViewSubmenu, // Hauptmenue / Listen
    DeviceTestViewWidget, // generische Info-/Status-Anzeige
    DeviceTestViewVarItemList, // Einstellungen pro Modul
    DeviceTestViewTextBox, // scrollbare Logs / Dumps
} DeviceTestView;

/** Das zentrale App-Objekt. Wird an jede Scene als context uebergeben. */
typedef struct {
    Gui* gui;
    ViewDispatcher* view_dispatcher;
    SceneManager* scene_manager;
    NotificationApp* notifications;

    // Geteilte Views (alle Module greifen darauf zu)
    Submenu* submenu;
    Widget* widget;
    VariableItemList* var_item_list;
    TextBox* text_box;
} DeviceTestApp;

/**
 * Bequemer Helfer: zeigt eine scrollbare Textseite im Widget-View an.
 * Jedes Modul-Geruest nutzt das, um Zweck + Status darzustellen, bis die
 * echte Logik eingebaut wird.
 */
void devicetest_show_placeholder(DeviceTestApp* app, const char* title, const char* body);
