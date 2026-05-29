#include "cardReader.h"

void tCardRead (void * pvParameters) {
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();
	for ( ;; ) {
        // Scans continuously for an NFC tag
        nfcTagReader.findNFCTag();
	    vTaskDelayUntil (& xLastWakeTime, pdMS_TO_TICKS (2000)); // Checks every 500ms
	}
}

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

void cardReader::findNFCTag() {
    if (nfc->readPassiveTargetID(PN532_MIFARE_ISO14443A,uid,&uidLength)) {
        // Implement some output for successful card read
        if (uidLength == 4) {
            cardid <<= 8;
            cardid |= uid[1];
            cardid <<= 8;
            cardid |= uid[2];
            cardid <<= 8;
            cardid |= uid[3];
            // Implement some output saying this is a MiFare Classic Card, with cardid card number.
            // TODO: Send cardid as a queue
        }
    }
}