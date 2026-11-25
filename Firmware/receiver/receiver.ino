#include <RadioLib.h>

#define PIN_SCK   18
#define PIN_MISO  19
#define PIN_MOSI  23
#define PIN_NSS    5
#define PIN_DIO1  27
#define PIN_RST   13
#define PIN_BUSY   4
#define PIN_TXEN  25
#define PIN_RXEN  26

SX1280 radio = new Module(PIN_NSS, PIN_DIO1, PIN_RST, PIN_BUSY);

volatile bool packetReady = false;

void IRAM_ATTR onPacket() {
  packetReady = true;
}

void setup() {
  Serial.begin(115200);
  SPI.begin(PIN_SCK, PIN_MISO, PIN_MOSI, PIN_NSS);
  radio.setRfSwitchPins(PIN_RXEN, PIN_TXEN);

  int state = radio.begin(2400.0, 812.5, 9, 7, RADIOLIB_SX128X_SYNC_WORD_PRIVATE, 0);
  if (state != RADIOLIB_ERR_NONE) {
    Serial.print("SX1280 init failed, code ");
    Serial.println(state);
    while (true) delay(1000);
  }

  radio.setPacketReceivedAction(onPacket);
  radio.startReceive();
  Serial.println("Receiver listening");
}

void loop() {
  if (!packetReady) return;
  packetReady = false;

  String msg;
  int state = radio.readData(msg);
  if (state == RADIOLIB_ERR_NONE) {
    Serial.print("Got: ");
    Serial.print(msg);
    Serial.print("  RSSI ");
    Serial.print(radio.getRSSI());
    Serial.print(" dBm  SNR ");
    Serial.print(radio.getSNR());
    Serial.println(" dB");
  } else if (state == RADIOLIB_ERR_CRC_MISMATCH) {
    Serial.println("Packet with bad CRC");
  } else {
    Serial.print("Receive failed, code ");
    Serial.println(state);
  }
  radio.startReceive();
}
