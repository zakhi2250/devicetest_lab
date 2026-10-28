/**
 * Zentrale Modul-/Scene-Liste (X-Macro).
 *
 * JEDES Modul wird hier GENAU EINMAL eingetragen. Aus dieser Liste werden
 * automatisch erzeugt:
 *   - das Scene-Enum (DeviceTestScene<Id>)
 *   - die Funktions-Prototypen (on_enter/on_event/on_exit)
 *   - die Handler-Tabellen fuer den SceneManager
 *
 * Neues Modul hinzufuegen = eine Zeile hier + eine Datei
 * scenes/devicetest_scene_<name>.c. Mehr nicht. Siehe docs/EXTENDING.md.
 *
 * Format:  ADD_SCENE(prefix, dateiname_suffix, EnumId)
 */

ADD_SCENE(devicetest, main_menu, MainMenu)

// --- Funk / RF ---------------------------------------------------------------
ADD_SCENE(devicetest, ir, Ir) // Infrarot: TV & AV-Geraete
ADD_SCENE(devicetest, subghz, Subghz) // Sub-GHz: 433/868-MHz-Funk

// --- Kontaktlos --------------------------------------------------------------
ADD_SCENE(devicetest, nfc, Nfc) // NFC 13,56 MHz
ADD_SCENE(devicetest, rfid, Rfid) // RFID 125 kHz
ADD_SCENE(devicetest, ibutton, Ibutton) // 1-Wire iButton

// --- Kabel / PC / Hardware ---------------------------------------------------
ADD_SCENE(devicetest, gpio, Gpio) // GPIO-Pins: Status/Steuern
ADD_SCENE(devicetest, uart, Uart) // UART-Konsole ueber GPIO
ADD_SCENE(devicetest, i2c, I2c) // I2C-Bus-Scanner
ADD_SCENE(devicetest, spi, Spi) // SPI-Bus-Test
ADD_SCENE(devicetest, badusb, Badusb) // BadUSB: eigene HID-Skripte
ADD_SCENE(devicetest, u2f, U2f) // U2F-Sicherheitsschluessel

// --- Mess- / Hilfsmodule -----------------------------------------------------
ADD_SCENE(devicetest, sensors, Sensors) // 1-Wire/Analog-Sensoren
ADD_SCENE(devicetest, selftest, Selftest) // Hardware-Selbsttest
ADD_SCENE(devicetest, logger, Logger) // Ergebnis-Log / Historie
ADD_SCENE(devicetest, about, About) // Info & Rechtlicher Hinweis
