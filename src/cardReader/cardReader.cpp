#include "cardReader.h"

void cardReader::setup() {
    // Set up hardware connections
    PN532_I2C.begin(Pins::PN532_SDA, Pins::PN532_SCL);
    nfc = new Adafruit_PN532(Pins::PN532_IRQ, Pins::PN532_RST, &PN532_I2C);
    uint32_t versionData = nfc->getFirmwareVersion();
    if (!versionData) {
        // Implement LCD output for error
        while (1); // halt
    }
    // Implement LCD output for chip found
}

void cardReader::readDataBlock(uint8_t blockNumber) {
    bool success; // Used for error handling
    if (((nfc->mifareclassic_IsTrailerBlock(blockNumber)) == 0) && (blockNumber != 0)) {
        success = nfc->mifareclassic_AuthenticateBlock(uid, uidLength, blockNumber, keyNum, keyA);
    }
}