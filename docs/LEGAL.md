# Rechtlicher & verantwortungsvoller Umgang

Dieses Werkzeug ist für **autorisiertes Testen deiner eigenen Geräte** und zum
**Lernen** gedacht. Kurz und ehrlich:

## Grundregel

> Nur an Hardware, die **dir gehört** oder für die du eine **ausdrückliche
> Erlaubnis** des Eigentümers hast.

Das gilt besonders für die Module **NFC, RFID, iButton** (fremde Karten/Tags
nicht lesen/klonen), **BadUSB/U2F** (nur eigener PC) und **Sub-GHz** (keine
fremden Tore/Autos/Geräte).

## Funk (Sub-GHz & IR)

- **Frequenzen & Sendeleistung** sind je nach Land reguliert. Nutze Sub-GHz
  nur in den **bei dir erlaubten Bändern** (in der EU typischerweise Teile von
  433,05–434,79 MHz und 868 MHz als SRD-Bänder, mit Grenzen für Leistung und
  Sendedauer).
- Das Sub-GHz-Modul soll eine **Frequenz-Whitelist** erzwingen: Senden nur,
  wenn die Frequenz zulässig ist. Entferne diese Prüfung nicht.
- **Rolling-Code**-Systeme (moderne Autos, viele Garagentore) lassen sich nicht
  einfach „wiederholen"; Versuche, sie zu überlisten, können zudem illegal sein.

## Was der Flipper grundsätzlich nicht kann

Unabhängig von dieser Software: **EMV-Bankkarten** klonen, moderne
**Rolling-Code-Autos** öffnen, **WPA3** knacken. Erwarte das nicht — und
Anleitungen, die das versprechen, sind unseriös.

## Daten & Privatsphäre

Dumps (z. B. `.nfc`) können personenbezogene oder sicherheitsrelevante Daten
enthalten. Bewahre sie sicher auf und teile sie nicht.

## Verantwortung

Die Nutzung erfolgt auf **eigene Verantwortung**. Die Gesetze zu Funk,
Datenschutz und Zugangskontrolle unterscheiden sich je nach Land und Situation.
Im Zweifel: informieren, bevor du sendest oder ausliest.

---

*Dies ist eine technische Hinweisdatei, keine Rechtsberatung.*
