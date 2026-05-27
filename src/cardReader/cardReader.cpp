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

void cardReader::readCardData() {
    // Reads all blocks from 0 to 63. Will not read first block (1 total) or section trailers (16 total). Total blocks read is 47.
    for (int currentBlock = 0; currentBlock < 64; currentBlock++)
    if (((nfc->mifareclassic_IsTrailerBlock(currentBlock)) == 0) && (currentBlock != 0)) {
        if (nfc->mifareclassic_AuthenticateBlock(uid, uidLength, currentBlock, keyNum, keyA)) {
            if (nfc->mifareclassic_ReadDataBlock(currentBlock, blockData)) {
                memcpy(cardData[currentBlock],blockData,16);
            } else {
                // Implement LCD output for readblock error
            }
        } else {
            // Implement LCD output for authentication error
        }
    }

}