---
title: "ESP32 Transmitter and Receiver"
github: "[your repo](https://github.com/whosthedoctor/ESP32-Transmitter-and-Receiver/)"
description: "Create a Long Range transmitter for my ESP32 that can do standard radio and drone protocols, stable, low packet loss, and 40 km range"
created_at: "2026-11-5"
total_time: ""
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
The amplifier needs to have power, low noise, and the TX/RX antenna switch, and needs to boost the chip to a reasonable distance.
All parts NEED to run on 3.3V, undecided whether or not to feed it on 5v and then regulate that to 3.3v.

Specific Parts:
Radio Chip: SX1280, as its small, highly sensitive, and can do LoRa, as well as FLRC, GFSK, BLE, and ExpressLRS is based on the other ones, and has 12.5 dBm.
Amplifier: RFX2401C, as it has all three parts, and boosts the 12.5 dBm to 20 dBm, which is 2.4x the range in open air, and it runs on 2.0-3.6v.
Crystal: JLYE Y201652MEBCX, has 52 MHz, and is small.


<img width="404" height="122" alt="Screenshot 2026-11-25 at 2 28 40 PM" src="https://github.com/user-attachments/assets/f63c5abe-2370-4717-8c59-80af86fd7d49" />

Pinouts:
Radio Chip:
<img width="1000" height="1000" alt="image" src="https://github.com/user-attachments/assets/445efd34-9e97-483b-8525-07d7f664ed15" />

Amp:
<img width="304" height="296" alt="image" src="https://github.com/user-attachments/assets/fd32984f-af3a-42da-8bca-3df970540481" />

Crystal just has 4 pads, no pinout image online

**Total time spent: 40m**


## November 7, 2026: Creating the Schematic and Finding Smaller Parts

Installed KiCAD and started working on the schematic. I first tried to find a schematic for the amp and radio chip, but then had to make one myself in the editor. I then worked on the schematic, adding smaller parts as I went. 
# Extra Parts:
I need a regulator, might as well start on 5v because 5v regulators are common.
Using the AP2112K 3.3v regulator

<img width="430" height="400" alt="image" src="https://github.com/user-attachments/assets/3923e321-a064-4095-8a37-7bf152b990b8" />

Parts needed bc of added main part: 
C11: 0.1 microF, input cap 
C1: 10 microF, bulk cap on 3.3v and gnd
C9, C10 0.1 microF: decoupling caps for 3.3v and gnd

Radio Chip Parts:
C2 0.1 microF: regulator for radio chip cap
C13 470 nF: voltage pins 2 and 12 on the SX1280 connected (theres on on the SX1280, but not reliable so using the LDO instead.)

Power LED (because if theres no power led, is it even a real pcb?):
R1 1k: Connected to 5v
D1 red LED

RF Matching and Filter:
C5 1.2pF: U1 pin 22 to gnd as a shunt cap
L1 3.0nH: u1 pin 22 to C6 in series inductor
C6 0.8pF: L1 to gnd as shunt
L2 2.5nH: C6 node to C12 node in series
C19 0.5pF: C12 node to gnd shunt
C18 100pF (DNP): shunt to gnd, not needed
C12 1.2pF: C12 to U2 pin 4 TXRX

Amplifier Control:
R2 1k: pin 10 to U2 pin 5
R3 1k: pin 11 to U2 pin 6

Connectors and desired pinout:
J1, a 2x6 socket(its in schematic as 1x12 but I forgot to change it): 1 = 5v, 2= gnd, 3= sck, 4 = MISO, 5= mosi, 6= NSS, 7 = BUSY, 8 = DIO1, 9 = RST, 10 = TXEN, 11 = RXEN, 12 = GND
J2, SMA, using Amphenol 132289 footprint but KiCAD doesnt place sma connectors so thats from Amazon ig
DNP Caps: C3 and C4 to calibrate the crystal, and C7(i couldnt figure out how to remove it its just DNP) 


Schematic:

<img width="934" height="828" alt="Screenshot 2026-11-25 at 2 41 30 PM" src="https://github.com/user-attachments/assets/d8467539-8cb9-4165-8e1d-ff8bc46d641f" />

BOM so far:

<img width="494" height="494" alt="Screenshot 2026-11-25 at 2 55 48 PM" src="https://github.com/user-attachments/assets/c8b116c8-2452-4868-8fa7-9787eeab25f2" />

**Total time spent: 4h**


## November 8, 2026: Working on the pcb (later its V1)

Just putting all the traces together, make the LDO close to the pins, and just place things in other places. Not much to say, but the gnd pours are connected, and the vias were too big and i made the setting smaller.
0.5mm for power, 0.2 or 0.3mm for signal traces.
The nets from the pin header mistake in schematic are unassigned, so i had to reassign them.

<img width="1266" height="827" alt="Screenshot 2026-11-25 at 3 06 53 PM" src="https://github.com/user-attachments/assets/07d662ed-4abf-49da-b7b1-9b220f9aa19b" />

<img width="857" height="597" alt="Screenshot 2026-11-25 at 3 07 07 PM" src="https://github.com/user-attachments/assets/80066f0d-6a92-4998-a402-a743e5b59eb9" />

**Total time spent: 1.5h**

## November 12, 2026: Making a V2, because V1 was too big

Just rearranged components and tried to unify the gnd pour without making it too big. and i learned how to put images on boards

<img width="821" height="551" alt="Screenshot 2026-11-25 at 3 10 08 PM" src="https://github.com/user-attachments/assets/6db126b4-6fc5-4673-8b32-6d5c678086cf" />

<img width="1120" height="570" alt="Screenshot 2026-11-25 at 3 09 48 PM" src="https://github.com/user-attachments/assets/1b743982-8a88-4cf6-bfd8-782b5a9186ac" />

<img width="944" height="514" alt="Screenshot 2026-11-25 at 3 10 26 PM" src="https://github.com/user-attachments/assets/e95f2b04-1a1d-4ec5-a4bd-a5042fd87a20" />


**Total time spent: 1.3h**
