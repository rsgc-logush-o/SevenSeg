#include "Arduino.h"
#include "sevenSeg.h"

SevenSeg::SevenSeg(uint8_t numberOfDisplays, uint8_t clockPin, uint8_t dataPin, uint8_t latchPin)
{
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);
	pinMode(latchPin, OUTPUT);

	_clockPin = clockPin;
	_dataPin = dataPin;
	_latchPin = latchPin;
	_numberOfDisplays = numberOfDisplays;

	

	#define NULL 11
	#define MINUS 10
	

	

	for(int i = 0; i < _numberOfDisplays; i++)
	{
		prevDisplayed[i] = NULL;
	}
}

void SevenSeg::displayInt(uint8_t displayNumber, uint8_t numberToDisplay, bool decimal)
{
	
	prevDisplayedDecimal[displayNumber] = decimal;
	prevDisplayed[displayNumber] = numberToDisplay;

	digitalWrite(_latchPin, LOW);

	for(int i = _numberOfDisplays - 1;  i > -1; i--)
	{

		if(prevDisplayedDecimal[i])shiftData(numbers[prevDisplayed[i]] & B00010000);
		else shiftData(numbers[prevDisplayed[i]]);
	}

	digitalWrite(_latchPin, HIGH);
	
}

void SevenSeg::shiftData(uint8_t dataToShift)
{
	for(int i = 0; i < 8; i++)
	{
		digitalWrite(_clockPin, LOW);

		digitalWrite(_dataPin, 1 << i & dataToShift);

		digitalWrite(_clockPin, HIGH);

	}
}
