/* A seven segment display library for the 74HC595 shift registers
Written By Oliver Logush in 2016, Version 1*/


#ifndef SevenSeg_h
#define SevenSeg_h

#include "Arduino.h"

class SevenSeg
{
  public:
    SevenSeg(uint8_t numberOfDisplays, uint8_t clockPin, uint8_t dataPin, uint8_t latchPin);
    void displayInt(uint8_t displayNumber, uint8_t numberToDisplay, bool decimal = false);
  private:
    uint8_t _numberOfDisplays;
    uint8_t _clockPin;
    uint8_t _dataPin;
    uint8_t _latchPin;
    void shiftData(uint8_t dataToShift);
    uint8_t numbers[11] = {B11100111, B00100001, B11001011, B01101011, B00101101, B01101110, B11101110, B00100011, B11101111, B01101111, B00001000};
    uint8_t prevDisplayed[10];
    bool prevDisplayedDecimal[10];
};


#endif
