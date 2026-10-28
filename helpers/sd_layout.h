/**
 * Zentrale SD-Karten-Pfade. Jedes Modul speichert Dumps/Logs hierunter.
 * Verzeichnisse werden beim ersten Schreiben per storage_common_mkdir
 * angelegt (siehe docs/EXTENDING.md).
 */
#pragma once

#define DEVICETEST_DIR "/ext/apps_data/devicetest_lab"

#define DEVICETEST_DIR_NFC DEVICETEST_DIR "/nfc"
#define DEVICETEST_DIR_RFID DEVICETEST_DIR "/rfid"
#define DEVICETEST_DIR_IR DEVICETEST_DIR "/ir"
#define DEVICETEST_DIR_SUBGHZ DEVICETEST_DIR "/subghz"
#define DEVICETEST_DIR_IBUTTON DEVICETEST_DIR "/ibutton"
#define DEVICETEST_DIR_LOGS DEVICETEST_DIR "/logs"
