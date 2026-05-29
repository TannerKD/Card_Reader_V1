#ifndef PINS_H
#define PINS_H

#include <cstdint>

// Hardware pin connections
// LED_INTERNAL is the system heartbeat
// PN532_SDA and PN532_SCL communicate with the PN532 module
// LCD_DB{7-4},E,RS communicate with the LCD display.
// Note: To save pins later on, we could implement some shift register application to drive LCD at lower pin cost.
namespace Pins {
    constexpr uint8_t LED_INTERNAL = 2;
    constexpr uint8_t PN532_SDA = 22;
    constexpr uint8_t PN532_SCL = 23;
    constexpr uint8_t PN532_IRQ = 25;
    constexpr uint8_t PN532_RST = 26;
    constexpr uint8_t LCD_DB7 = 25;
    constexpr uint8_t LCD_DB6 = 26;
    constexpr uint8_t LCD_DB5 = 27;
    constexpr uint8_t LCD_DB4 = 14;
    constexpr uint8_t LCD_E = 12;
    constexpr uint8_t LCD_RS = 13;
}

// Handles pin setup for relevant pins
void pin_setup();

// Heartbeat pulse
void tPulseLED(void *pvParameters);

#endif