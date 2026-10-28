/**
 * Scene-Handler-Tabellen, automatisch aus devicetest_scene_config.h erzeugt.
 * Diese Datei muss normalerweise nie angefasst werden.
 */
#include "devicetest_scene.h"

// on_enter-Tabelle
#define ADD_SCENE(prefix, name, id) prefix##_scene_##name##_on_enter,
void (*const devicetest_scene_on_enter_handlers[])(void*) = {
#include "devicetest_scene_config.h"
};
#undef ADD_SCENE

// on_event-Tabelle
#define ADD_SCENE(prefix, name, id) prefix##_scene_##name##_on_event,
bool (*const devicetest_scene_on_event_handlers[])(void* context, SceneManagerEvent event) = {
#include "devicetest_scene_config.h"
};
#undef ADD_SCENE

// on_exit-Tabelle
#define ADD_SCENE(prefix, name, id) prefix##_scene_##name##_on_exit,
void (*const devicetest_scene_on_exit_handlers[])(void* context) = {
#include "devicetest_scene_config.h"
};
#undef ADD_SCENE

// Gesamt-Handler-Struktur
const SceneManagerHandlers devicetest_scene_handlers = {
    .on_enter_handlers = devicetest_scene_on_enter_handlers,
    .on_event_handlers = devicetest_scene_on_event_handlers,
    .on_exit_handlers = devicetest_scene_on_exit_handlers,
    .scene_num = DeviceTestSceneNum,
};
