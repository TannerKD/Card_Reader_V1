#include "cardReader.h"

void cardReader::setup() {
    // Set up hardware connections
    PN532_I2C.begin(Pins::PN532_SDA, Pins::PN532_SCL);
    nfc = new Adafruit_PN532(Pins::PN532_IRQ, Pins::PN532_RST, &PN532_I2C);

}