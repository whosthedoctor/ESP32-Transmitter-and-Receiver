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

const int8_t TX_POWER_DBM = 0;

uint32_t counter = 0;

void setup() {
  Serial.begin(115200);
  SPI.begin(PIN_SCK, PIN_MISO, PIN_MOSI, PIN_NSS);

  radio.setRfSwitchPins(PIN_RXEN, PIN_TXEN);

  // 2400 MHz, 812.5 kHz BW, SF9, CR 4/7, private sync word
  int state = radio.begin(2400.0, 812.5, 9, 7, RADIOLIB_SX128X_SYNC_WORD_PRIVATE, TX_POWER_DBM);
  if (state != RADIOLIB_ERR_NONE) {
    Serial.print("SX1280 init failed, code ");
    Serial.println(state);
    while (true) delay(1000);
  }
  Serial.println("Transmitter ready");
}

void loop() {
  String msg = "Hello #" + String(counter++);
  int state = radio.transmit(msg);
  if (state == RADIOLIB_ERR_NONE) {
    Serial.print("Sent: ");
    Serial.println(msg);
  } else {
    Serial.print("Send failed, code ");
    Serial.println(state);
  }
  delay(1000);
}
