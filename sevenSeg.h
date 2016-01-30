/* A seven segment display library for the 74HC595 shift registers
Written By Oliver Logush in 2016, Version 1*/


#ifndef SevenSeg_h
#define SevenSeg_h

#include "Arduino.h"

class SevenSeg
{
  public:
    SevenSeg(uint8_t numberOfDisplays, uint8_t clockPin, uint8_t dataPin, uint8_t latchPin);
    void displayInt(uint8_t numberToDisplay);
    void displayFloat(float numberToDisplay, uint8_t floatWidth);
  private:
    uint8_t _numberOfDisplays;
    uint8_t _clockPin;
    uint8_t _dataPin;
    uint8_t _latchPin;
    void shiftData(uint8_t dataToShift);
    uint8_t numbers[10];
    uint8_t error;
};


#endif
