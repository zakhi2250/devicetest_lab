# Module

Jedes Modul ist eine eigene Scene unter `scenes/`. Hier steht pro Modul:
**Zweck**, **genutzte Flipper-API** und **was als Nächstes einzubauen ist**.
Das Grundgerüst zeigt jedes Modul bereits im Menü an; die Hardware-Logik wird
schrittweise ergänzt.

Empfohlene Umsetzungs-Reihenfolge (von einfach/risikoarm zu komplex):
**IR → NFC → RFID → iButton → Sub-GHz → GPIO → UART → I²C → SPI → Sensoren →
Selbsttest → BadUSB → U2F → Logger.**

---

## Funk / RF

### IR — `devicetest_scene_ir.c`
- **Zweck:** Fernseher, Soundbar, Beamer u. Ä. steuern/testen.
- **Kann:** Codes vom Empfänger anlernen, als `.ir` speichern, über die drei
  IR-LEDs senden, Universal-Remote (Power/Vol/Source) durchprobieren.
- **API:** `infrared_worker_rx/tx`, `infrared_signal`, `storage`, Dialoge.
- **Risiko:** gering (nur eigene Geräte).

### Sub-GHz — `devicetest_scene_subghz.c`
- **Zweck:** eigene 433/868-MHz-Fernbedienungen & Sensoren testen.
- **Kann:** Frequenz-Analyzer (RSSI), lesen → `.sub`, erneut senden.
- **API:** `subghz_devices`, `subghz_worker`, `furi_hal_subghz`.
- **Wichtig:** **Frequenz-Whitelist erzwingen** — nur lokal erlaubte Bänder;
  Senden nur, wenn die Frequenz zulässig ist. Siehe [`LEGAL.md`](LEGAL.md).

## Kontaktlos

### NFC — `devicetest_scene_nfc.c`
- **Zweck:** eigene 13,56-MHz-Karten/Tags auslesen & verstehen.
- **Kann:** ISO14443-A/B lesen, UID + Typ, MIFARE-Classic-Keys per Dictionary
  versuchen, Dump → `.nfc`, eigene Karte emulieren.
- **API:** `nfc`, `nfc_device`, `nfc_poller`, `nfc_dict`.

### RFID 125 kHz — `devicetest_scene_rfid.c`
- **Zweck:** ältere LF-Tags (EM4100, HID Prox).
- **Kann:** lesen + UID, auf leere T5577 schreiben, `.rfid` speichern.
- **API:** `lfrfid_worker`, `protocol_dict`.

### iButton — `devicetest_scene_ibutton.c`
- **Zweck:** 1-Wire-Kontaktschlüssel (Dallas u. a.).
- **Kann:** lesen + UID, emulieren, auf Rohling schreiben, `.ibtn`.
- **API:** `ibutton_worker`, `ibutton_protocols`.

## Kabel / PC / Hardware

### GPIO — `devicetest_scene_gpio.c`
- **Zweck:** die 18 Pins testen.
- **Kann:** Pegel live lesen, Pin als Aus-/Eingang schalten, 3,3V/5V-Ausgang.
- **API:** `furi_hal_gpio`, `furi_hal_power` (5 V an Pin 1).

### UART-Konsole — `devicetest_scene_uart.c`
- **Zweck:** serielle Konsole eigener Geräte (Router, SBCs, Boards) anzeigen.
- **Kann:** Baudrate wählen, RX live im TextBox, optional Mitschnitt → SD.
- **API:** `furi_hal_serial`, `furi_stream_buffer` (TX/RX an GPIO 13/14).

### I²C-Scanner — `devicetest_scene_i2c.c`
- **Zweck:** angeschlossene I²C-Chips finden.
- **Kann:** Adressraum 0x08–0x77 scannen, Geräte auflisten, Register lesen.
- **API:** `furi_hal_i2c` (externer Bus, Pins C0/C1 = 15/16).

### SPI-Test — `devicetest_scene_spi.c`
- **Zweck:** SPI-Bauteile prüfen (z. B. Flash-Chips).
- **Kann:** Byte-Transfers, JEDEC-ID lesen, Verkabelung testen.
- **API:** `furi_hal_spi` (externer Bus).

### BadUSB — `devicetest_scene_badusb.c`
- **Zweck:** **eigene** Tastatur-/Automatisierungsskripte am eigenen PC laufen lassen.
- **Kann:** `.txt` (Ducky-Syntax) von SD wählen, Layout setzen, als USB-HID abspielen.
- **API:** `furi_hal_usb_hid`, `bad_usb_script`.
- **Nur** an eigener Hardware.

### U2F — `devicetest_scene_u2f.c`
- **Zweck:** Flipper als FIDO-U2F-Schlüssel für eigene Logins testen.
- **API:** `furi_hal_usb` (u2f), `u2f_data`.

## Mess / Hilfe

### Sensoren — `devicetest_scene_sensors.c`
- **Zweck:** Temperatur/Feuchte u. a. über GPIO messen (DS18B20, DHT).
- **API:** `furi_hal_gpio`, 1-Wire-Host, `furi_hal_adc`.

### Hardware-Selbsttest — `devicetest_scene_selftest.c`
- **Zweck:** den Flipper selbst prüfen.
- **Kann:** LED/Vibro/Ton, Akku & Temperatur, SD erkannt?, Funk-Chips antworten?
- **API:** `notification`, `furi_hal_power`, `furi_hal_speaker`, `storage`.

### Log / Historie — `devicetest_scene_logger.c`
- **Zweck:** Ergebnisse zentral auf der SD-Karte.
- **Kann:** Test-Historie anzeigen, Textlog unter `/ext/apps_data/devicetest_lab/logs/`.
- **API:** `storage`, `furi_string`, `text_box`. Pfade in `helpers/sd_layout.h`.

### Info & Recht — `devicetest_scene_about.c`
- Version + rechtlicher Kurzhinweis.
