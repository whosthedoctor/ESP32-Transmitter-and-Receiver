# ESP32-Transmitter-and-Receiver

This is designed as a custom ESP32 transmitter and receiver that can use LoRA (2.4 GHz), FLRC, and GFSK protocols. 

My initial goal for this project was to simply make a custom transmitter and receiver for my custom FPV drone, as it was originally using the PCB radio on an ESP-32, but soon grew into a very complex PCB routing and schematic design project. 

I learned lots of useful techniques in KiCAD and JLCPCB, such as routing, layering, vias, copper pours, and constraints with RF signal routing, which I will use in my future to make even more complex PCBs!

The radio amplifier and transceiver module is based on the SX1280IMLTRT transceiver IC and an RFX2401C RF front-end.

In order to fit the requirements on my drone, instead of putting bulky screw holes, my goal for the entire board was to make it as small and efficient as possible.

# PCB + Wiring Diagram

## Schematic
<img width="682" height="683" alt="Screenshot 2026-11-11 at 6 53 47 PM" src="https://github.com/user-attachments/assets/3af03ed3-1a6d-4b41-8644-8591e59b14fe" />
## PCB
### Backside
<img width="963" height="474" alt="Screenshot 2026-11-11 at 6 55 00 PM" src="https://github.com/user-attachments/assets/4c9c1eb7-7cc6-4207-9680-8b5ed7fd2714" />
### Frontside
<img width="962" height="523" alt="Screenshot 2026-11-11 at 6 54 46 PM" src="https://github.com/user-attachments/assets/5d9edeb4-755f-42fb-82f2-f4c641671d9d" />
### Topside
<img width="896" height="485" alt="Screenshot 2026-11-11 at 6 59 27 PM" src="https://github.com/user-attachments/assets/766f0370-9c3f-451d-86fa-eb5172a674fb" />
### Bottom
<img width="907" height="464" alt="Screenshot 2026-11-11 at 6 59 53 PM" src="https://github.com/user-attachments/assets/f9c060f9-fe18-44a5-b847-dff31d9f899c" />
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
| J1 | RP-SMA Female Edge Mount Connector (1.6mm PCB) | Dongguan Linconn | SMA-KFD01 | C496551 | 1 | $0.65 | $0.65 | https://www.lcsc.com/product-detail/C496551.html |
| J2 | 1x12 Male Header (2.54mm / 0.1" pitch) | Changjiang | A2541WV-12P | C2833334 | 1 | $0.20 | $0.20 | https://www.lcsc.com/product-detail/C2833334.html |
| X1 | 52 MHz 4-pad SMD Crystal (±10 ppm, 10 pF load) | HCI | XC21M4-52.000-F10NNHPL | C3034316 | 1 | $0.12 | $0.12 | https://www.lcsc.com/product-detail/C3034316.html |
| U3 | 3.3V Low-Noise LDO Regulator (500mA) | Diodes Inc. | AP2112K-3.3TRG1 | C51118 | 1 | $0.22 | $0.22 | https://www.lcsc.com/product-detail/C51118.html |
| C1, C2 | 10 µF 10V X5R 0603 Ceramic Bulk Capacitors | Samsung | CL10A106KP8NNNC | C19702 | 2 | $0.05 | $0.10 | https://www.lcsc.com/product-detail/C19702.html |
| C3-C8 | 0.1 µF 50V X7R 0603 Decoupling Capacitors | Murata | GRM188R71H104KA93D | C77055 | 6 | $0.02 | $0.12 | https://www.lcsc.com/product-detail/C77055.html |
| C11 | 1.5 pF 50V C0G 0402 RF Matching Capacitor | Murata | GRM1555C1H1R5BA01D | C76957 | 1 | $0.02 | $0.02 | https://www.lcsc.com/product-detail/C76957.html |
| C12 | 1.0 pF 50V C0G 0402 RF Matching Capacitor | Murata | GRM1555C1H1R0BA01D | C76952 | 1 | $0.02 | $0.02 | https://www.lcsc.com/product-detail/C76952.html |
| L1 | 1.0 nH 0402 High-Q RF Inductor | Murata | LQG15HS1N0S02D | C18222 | 1 | $0.03 | $0.03 | https://www.lcsc.com/product-detail/C18222.html |
| L2 | 4.7 nH 0402 High-Q RF Inductor | Murata | LQG15HS4N7S02D | C86065 | 1 | $0.03 | $0.03 | https://www.lcsc.com/product-detail/C86065.html |
| R1 | 1 kΩ 1% 0402 SMD Resistor for D1 Power Indicator LED | UNI-ROYAL | 0402WGF1001TCE | C25744 | 1 | $0.01 | $0.01 | https://www.lcsc.com/product-detail/C25744.html |
| R2 | 0 Ω 0603 Jumper Resistor | UNI-ROYAL | 0603WAF0000T5E | C21189 | 1 | $0.01 | $0.01 | https://www.lcsc.com/product-detail/C21189.html |
| ANT1 | 2.4GHz Rubber Duck Antenna (SMA Male, 2.5dBi) | ZIISOR | TX2400-JZR-6 | C54321745 | 1 | $0.90 | $0.90 | https://www.lcsc.com/product-detail/C54321745.html |
| R3, R4 | 1 kΩ 1% 0603 TXEN/RXEN Series Resistors | UNI-ROYAL | 0603WAF1001T5E | C21190 | 2 | $0.01 | $0.02 | https://www.lcsc.com/product-detail/C21190.html |
| PCB-FAB | PCB Fabrication (5x 2-Layer 1.6mm FR-4 PCBs) | JLCPCB | 1.6mm FR-4, HASL, 2-Layer, Green Mask | Custom Fab | 5 | $0.80 | $4.00 | https://jlcpcb.com/capabilities/pcb-capabilities |
| PCBA-SETUP | JLCPCB SMT Assembly Base Setup Fee | JLCPCB | SMT Production Line Setup & Calibration | PCBA Fee | 1 | $7.00 | $7.00 | https://jlcpcb.com/pcb-assembly |
| PCBA-SMT | SMT Component Placement & Stencil Fee | JLCPCB | Laser Cut SMT Stencil & High-Speed Pick-and-Place | PCBA Fee | 1 | $6.50 | $6.50 | https://jlcpcb.com/pcb-assembly |
| PCBA-LOAD | Extended Component Loading Fee (Unique LCSC parts) | JLCPCB | Specialty Reel Feeder Setup for Non-Basic Parts | LCSC Fee | 1 | $3.00 | $3.00 | https://jlcpcb.com/pcb-assembly |
| LOGISTICS | Express Shipping & Handling (Global Direct / DHL) | DHL / Global Direct | Air Express Shipping (3-5 Business Days) | Freight | 1 | $15.00 | $15.00 | https://www.dhl.com/ |
| **Component BOM Cost** | **SX1280 Transceiver BOM Components (5 Boards)** | **BOM Subtotal (SUM H2:H17 x 5)** | **5 Assembled Units** | **BOM Table** | **5** | **$7.80** | **$39.00** | |
| **Manufacturing & Assembly** | **JLCPCB PCB Fab, SMT Assembly & Shipping** | **M&A Subtotal (SUM H19:H23)** | **Fixed Batch (5 Boards)** | **JLCPCB Quote** | **5** | **$7.10** | **$35.50** | |
| **Total Production Cost** | **Complete Turnkey Prototype Build (5 Assembled Boards)** | **BOM Total + M&A Total (H27 + H28)** | **Complete Run (5 Boards)** | **Total Batch** | **5** | **$14.90** | **$74.50** | |
| **Per-Unit Production Cost** | **Effective Turnkey Cost per Assembled Board** | **Total Production Cost ÷ 5 Units (H29 / 5)** | **Per Assembled Unit** | **Unit Rate** | **1** | **$14.90** | **$14.90** | |
