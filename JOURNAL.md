---
title: "ESP32 Transmitter and Receiver"
github: "your repo"
description: "Describe your project in a short sentence!"
created_at: "2026-03-20"
total_time: "2h"
---

## November 6, 2026: Finding Parts

I started by figuring out what parts I needed to build a long-range radio receiver and transmitter.
You need an actual radio chip that creates radio signals.
You need a 52 MHz crystal to make frequencies to calibrate the chip
You need a matching network so that the radio chip can go into the amplifier without reflecting back
You need an amplifier and switch that boosts the signal
You need a connector.

The protocols LoRa and ExpressLRS, might as well do BLE as well, are needed on the radio chip.
The connector needs to be common, so I chose the SMA-connector, based on previous knowledge.
The radio chip needs to be legal and common, so here are the specs it needs to be: 2.4 GHz, under 30 dbm (legal limit)
The crystal HAS to be 52 MHz, and cannot be an oscillator module. Must be accurate as well.
The amplifier needs to have power, low-nosie, and the TX/RX antenna switch, and needs to boost the chip to a reasonable distance.
All parts NEED to run on 3.3V, undecided whether or not to feed it on 5v and then regulate that to 3.3v.

Specific Parts:
Radio Chip: SX1280, as its small, highly sensitive, and can do LoRa, as well as FLRC, GFSK, BLE, and ExpressLRS is based on the other ones, and has 12.5 dBm.
Amplifier: RFX2401C, as it has all three parts, and boosts the 12.5 dBm to 20 dBm, which is 2.4x the range in open air, and it runs on 2.0-3.6v.
Crystal: JLYE Y201652MEBCX, has 52 MHz, and is small.
<img width="404" height="122" alt="Screenshot 2026-11-25 at 2 28 40 PM" src="https://github.com/user-attachments/assets/f63c5abe-2370-4717-8c59-80af86fd7d49" />

**Total time spent: 40m**
