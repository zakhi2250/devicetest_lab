/**
 * Scene-Deklarationen, automatisch aus devicetest_scene_config.h erzeugt.
 * Diese Datei muss normalerweise nie angefasst werden.
 */
#pragma once

#include <gui/scene_manager.h>

// 1) Scene-Enum: DeviceTestSceneMainMenu, DeviceTestSceneIr, ...
#define ADD_SCENE(prefix, name, id) DeviceTestScene##id,
typedef enum {
#include "devicetest_scene_config.h"
    DeviceTestSceneNum,
} DeviceTestScene;
#undef ADD_SCENE

// 2) Handler-Tabelle fuer den SceneManager
extern const SceneManagerHandlers devicetest_scene_handlers;

// 3) Prototypen pro Scene:
//    devicetest_scene_<name>_on_enter/_on_event/_on_exit
#define ADD_SCENE(prefix, name, id)                                      \
    void prefix##_scene_##name##_on_enter(void* context);                \
    bool prefix##_scene_##name##_on_event(void* context, SceneManagerEvent event); \
    void prefix##_scene_##name##_on_exit(void* context);
#include "devicetest_scene_config.h"
#undef ADD_SCENE
