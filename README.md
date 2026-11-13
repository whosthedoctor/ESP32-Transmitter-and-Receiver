
# ESP32-Transmitter-and-Receiver

This is designed as a custom ESP32 transmitter and receiver that can use LoRA (2.4 GHz), FLRC, and GFSK protocols. 

My initial goal for this project was to simply make a custom transmitter and receiver for my custom FPV drone, as it was originally using the PCB radio on an ESP-32, but soon grew into a very complex PCB routing and schematic design project. 

I learned lots of useful techniques in KiCAD and JLCPCB, such as routing, layering, vias, copper pours, and constraints with RF signal routing, which I will use in my future to make even more complex PCBs!

The radio amplifier and transceiver module is based on the SX1280IMLTRT transceiver IC and an RFX2401C RF front-end.

In order to fit the requirements on my drone, instead of putting bulky screw holes, my goal for the entire board was to make it as small and efficient as possible.

# PCB + Wiring Diagram

I used KiCAD, as it is free, unlike something like Altium Designer, to design the PCB, find parts, and make schematics.

## Schematic
<img width="682" height="683" alt="Screenshot 2026-11-11 at 6 53 47 PM" src="https://github.com/user-attachments/assets/3af03ed3-1a6d-4b41-8644-8591e59b14fe" />

## PCB

### Backside

### Frontside

### Topside

### Bottom

## Wiring with Pins to ESP32 DevKit-C CP2012
| J1 Pin | Signal   | ESP32 GPIO | Notes                                        |
|:------:|----------|:----------:|----------------------------------------------|
| 1      | 5V       | 5V         | Powers the board's 3.3 V regulator           |
| 2      | GND      | GND        |                                              |
| 3      | SCK      | GPIO18     | SPI clock (VSPI)                             |
| 4      | MISO     | GPIO19     | Output from SX1280                           |
| 5      | MOSI     | GPIO23     |                                              |
| 6      | NSS (CS) | GPIO5      |                                              |
| 7      | BUSY     | GPIO4      | Input to ESP32                               |
| 8      | DIO1     | GPIO27     | Interrupt input                              |
| 9      | RST      | GPIO13     |                                              |
| 10     | TXEN     | GPIO25     | To RFX2401C through R2                       |
| 11     | RXEN     | GPIO26     | To RFX2401C through R3                       |
| 12     | GND      | GND        | Connect both ground pins                     |


## BOM
| Designator | Description | Manufacturer | Part Number | LCSC Part # | Quantity | Unit Price | Total Price | Direct Link |
| :--- | :--- | :--- | :--- | :--- | :---: | ---: | ---: | :--- |
| U1 | 2.4 GHz Transceiver IC (LoRa/FLRC/GFSK) | Semtech | SX1280IMLTRT | C125969 | 1 | $4.20 | $4.20 | https://www.lcsc.com/product-detail/C125969.html |
| U2 | 2.4 GHz RF Front-End (PA + LNA + TR Switch) | Skyworks / RFMD | RFX2401C | C19213 | 1 | $1.15 | $1.15 | https://www.lcsc.com/product-detail/C19213.html |
| J2 | SMA Female Edge Mount Connector (1.6mm PCB) — LCSC 0 stock, Other Suppliers, hand-solder | Amphenol | 132289 | C3172723 | 1 | $7.59 | $7.59 | https://www.lcsc.com/product-detail/C3172723.html |
| J1 | 2x6 Female Pin Socket (2.54mm pitch) — matches PinSocket_2x06 footprint | HDGC | HDGCPH2.54-PZS-2X6 | C19725274 | 1 | $0.19 | $0.19 | https://www.lcsc.com/product-detail/C19725274.html |
| Y2 | 52 MHz 4-pad SMD Crystal (±10 ppm, 10 pF load) — SMD2016 | HCI | XC21M4-52.000-F10NNHPL | C3034316 | 1 | $0.07 | $0.07 | https://www.lcsc.com/product-detail/C3034316.html |
| U3 | 3.3V Low-Noise LDO Regulator (500mA) — SOT-23-5 | Diodes Inc. | AP2112K-3.3TRG1 | C51118 | 1 | $0.22 | $0.22 | https://www.lcsc.com/product-detail/C51118.html |
| C1 | 10 µF 10V X5R 0402 Ceramic Bulk Capacitor (+3V3 rail) | Samsung | CL05A106MP5NUNC | C315248 | 1 | $0.03 | $0.03 | https://www.lcsc.com/product-detail/C315248.html |
| C2, C8, C9, C10, C11 | 0.1 µF 16V X7R 0402 Decoupling Capacitors | Murata | GRM155R71C104KA88D | C71629 | 5 | $0.01 | $0.05 | https://www.lcsc.com/product-detail/C71629.html |
| C5 | 1.5 pF 50V C0G 0402 RF Matching Capacitor | Murata | GRM1555C1H1R5BA01D | C76957 | 1 | $0.02 | $0.02 | https://www.lcsc.com/product-detail/C76957.html |
| C6 | 1.0 pF 50V C0G 0402 RF Matching Capacitor | Murata | GRM1555C1H1R0BA01D | C76952 | 1 | $0.02 | $0.02 | https://www.lcsc.com/product-detail/C76952.html |
| C13 | 470 nF 10V X5R 0402 DCC Filter Capacitor (SX1280 ref design C9) | Murata | GRM155R61A474KE15D | C77003 | 1 | $0.02 | $0.02 | https://www.lcsc.com/product-detail/C77003.html |
| C18 | 100 pF 50V C0G 0402 DC-Blocking Capacitor (RF path, series — add to schematic) | Murata | GRM1555C1H101JA01D | C77177 | 1 | $0.01 | $0.01 | https://www.lcsc.com/product-detail/C77177.html |
| L1 | 1.0 nH 0402 High-Q RF Inductor | Murata | LQG15HS1N0S02D | C18222 | 1 | $0.03 | $0.03 | https://www.lcsc.com/product-detail/C18222.html |
| L2 | 4.7 nH 0402 High-Q RF Inductor | Murata | LQG15HS4N7S02D | C86065 | 1 | $0.03 | $0.03 | https://www.lcsc.com/product-detail/C86065.html |
| R1, R2, R3 | 1 kΩ 1% 0402 SMD Resistors (R1 = D1 LED, R2/R3 = TXEN/RXEN series) | UNI-ROYAL | 0402WGF1001TCE | C25744 | 3 | $0.01 | $0.03 | https://www.lcsc.com/product-detail/C25744.html |
| D1 | Red 0402 SMD LED (power indicator, Vf 1.95V) | Kingbright | APHHS1005SURCK | C2852592 | 1 | $0.18 | $0.18 | https://www.lcsc.com/product-detail/C2852592.html |
| ANT1 | 2.4GHz Antenna, SMA Male, 2dBi, ~50mm — 2-pack $6.68 ($3.34/antenna); buy 3 packs for 5 boards | BOOBRIE | B0991PKTDL | B0991PKTDL | 1 | $3.34 | $3.34 | https://www.amazon.com/BOOBRIE-Antenna-802-11b-Aerial-Wireless/dp/B0991PKTDL |
| C14, C15, C16, C17 | In schematic, values TBD by John (DIO/DCC caps) — not orderable yet | TBD | TBD | TBD | 4 | $0.00 | $0.00 |  |
| PCB-FAB | PCB Fabrication (5x 2-Layer 1.6mm FR-4 PCBs) | JLCPCB | 1.6mm FR-4, HASL, 2-Layer, Green Mask | Custom Fab | 5 | $0.80 | $4.00 | https://jlcpcb.com/capabilities/pcb-capabilities |
| PCBA-SETUP | JLCPCB SMT Assembly Base Setup Fee | JLCPCB | SMT Production Line Setup & Calibration | PCBA Fee | 1 | $7.00 | $7.00 | https://jlcpcb.com/pcb-assembly |
| PCBA-SMT | SMT Component Placement & Stencil Fee | JLCPCB | Laser Cut SMT Stencil & High-Speed Pick-and-Place | PCBA Fee | 1 | $6.50 | $6.50 | https://jlcpcb.com/pcb-assembly |
| PCBA-LOAD | Extended Component Loading Fee (Unique LCSC parts) | JLCPCB | Specialty Reel Feeder Setup for Non-Basic Parts | LCSC Fee | 1 | $3.00 | $3.00 | https://jlcpcb.com/pcb-assembly |
| LOGISTICS | Express Shipping & Handling (Global Direct / DHL) | DHL / Global Direct | Air Express Shipping (3-5 Business Days) | Freight | 1 | $15.00 | $15.00 | https://www.dhl.com/ |
| **Component BOM Cost** | **SX1280 Transceiver BOM Components (5 Boards)** | **BOM Subtotal (SUM H2:H19 x 5)** | **5 Assembled Units** | **BOM Table** | **5** | **$17.18** | **$85.90** |  |
| **Manufacturing & Assembly** | **JLCPCB PCB Fab, SMT Assembly & Shipping** | **M&A Subtotal (SUM H21:H25)** | **Fixed Batch (5 Boards)** | **JLCPCB Quote** | **5** | **$7.10** | **$35.50** |  |
| **Total Production Cost** | **Complete Turnkey Prototype Build (5 Assembled Boards)** | **BOM Total + M&A Total (H29 + H30)** | **Complete Run (5 Boards)** | **Total Batch** | **5** | **$24.28** | **$121.40** |  |
| **Per-Unit Production Cost** | **Effective Turnkey Cost per Assembled Board** | **Total Production Cost ÷ 5 Units (H31 / 5)** | **Per Assembled Unit** | **Unit Rate** | **1** | **$24.28** | **$24.28** |  |

## Additional Notes
Although this is a kind of uneventful and not world-changing project like some of the other ones, it was quite fun. A lot of my projects got rejected already :'(

The reason I will be using JLCPCB over PCBWay is due to the marketing and reputation of JLCPCB, and I can't manufacture the PCBs in-house as I don't have any experience with it or have the materials with assembly.

Also if there are files called ESP-NOW..., the project was unable to be renamed in KiCAD and I originally wanted it to use ESP-NOW, but that is a WiFi protocol and not LR enough.

I played Factorio a couple years back, beat it, played Krastorio and SE, and it was more similar than not to trace routing. Very fun to do, actually!

Antennas (Amazon): the receiver/drone antenna is the BOOBRIE 2.4GHz SMA male (B0991PKTDL) — a 2-antenna pack, $6.68/pack ($3.34 each, better per-antenna rate than singles). One antenna per board, so 3 packs for 5 boards (1 spare). The transmitter/controller antenna is the HeelAooRC 2.4GHz ExpressLRS ES24TX Moxon (SMA plug, for the Micro TX module) — also a 2-antenna pack, $14.99/pack, 1 pack for the controller (1 used, 1 spare).

BOM rebuilt 2026-11-12 to match the schematic's designators: J1 is a 2x6 female socket (not the 1x12 male header the BOM used to say); the crystal is Y2 (not X1); the TXEN/RXEN series resistors are R2/R3 (not R3/R4) — the wiring table above already said R2/R3. All passives are 0402 to match the footprints (the old 0603 cap/resistor lines were the wrong package). C3/C4 crystal load caps are not populated — the SX1280 has ~10pF internal load, which matches the crystal. C12 (LDO bypass cap) is removed — the AP2112K has no BYP pin. C14–C17 are in the schematic but still need values. C18 is new: a 100pF DC-blocking cap that goes in series in the RF path (the SX1280's RFIO pin is DC-biased and the RFX2401C's TXRX pin is DC-shorted to ground, so the path needs a blocking cap) — it still has to be added to the schematic. LCSC prices are the lowest-tier unit prices; several parts have minimum order quantities (100 for the 0.1µF caps, 50 for the 100pF and 470nF caps, 20 for the 10µF cap, 5 for the LED and the header socket), so the true cash outlay is a little higher than the per-board subtotal.

## Test Code

No Hackatime as its a pretty short and basic script.

```
#include <RadioLib.h>
SX1280 radio = new Module(5, 27, 13, 4);
void setup() {
  SPI.begin(18, 19, 23, 5);
  radio.setRfSwitchPins(26, 25);
  radio.begin();
}
```
