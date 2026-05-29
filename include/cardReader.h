#ifndef CARDREADER_H
#define CARDREADER_H

#include <Adafruit_PN532.h>
#include "Wire.h"
#include "pins.h"

// Class Definition
class cardReader {
public:
    void setup();
    // reads data from block into blockData member variable. Possible block numbers are from 0-63.
    void readCardData();
    void findNFCTag();
    
private:
    TwoWire PN532_I2C = TwoWire(1); // For hardware wire setup
    Adafruit_PN532 *nfc; // creates PN532 object
    uint8_t uid[6] = {0, 0, 0, 0, 0, 0}; // UID of NFC Tag
    uint8_t uidLength; // Length of UID of NFC Tag
    uint8_t blockData[16]; // Used for extracting block data, which is 16 bytes long
    uint8_t cardData[47][16];
    uint8_t keyNum = 0; // Key number = 0: key A, Key number = 1: key B
    uint8_t keyA[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff}; // Basic key A for access to card
    uint32_t cardid = 0;
};

// Variables
extern cardReader nfcTagReader;

// Functions
void tCardRead(void *pvParameters);

#endif