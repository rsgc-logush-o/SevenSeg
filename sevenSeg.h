#ifndef SevenSeg_h
#define SevenSeg_h

#include "Arduino.h"

class SevenSeg
{
  public:
    SevenSeg(uint8_t numberOfDisplays, uint8_t clockPin, uint8_t dataPin, uint8_t latchPin);
    void display(uint8_t displayNumber, uint8_t numberToDisplay);
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
