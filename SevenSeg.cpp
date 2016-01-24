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

	error = B10000110;

	numbers[] = {B11100111, B00100001, B11001011, B01101011, B00101101, B01101110, B11101110, B00100011, B11101111, B01101111};
}

void SevenSeg::display(uint8_t numberToDisplay)
{
	if(numberToDisplay >= pow(10, _numberOfDisplays + 1))
	{
		digitalWrite(_latchPin, LOW);

		shiftData(error);

		digitalWrite(_latchPin, HIGH);
	}

	int numbersToShow[numberOfDisplays];

	for(int i = _numberOfDisplays - 1; i > -1; i--)
	{
		numbersToShow[i] = numberToDisplay / pow(10, i);
		numberToDisplay -= numbersToShow[i] * pow(10, i);
	}

	digitalWrite(_latchPin, LOW);

	for(int i = _numberOfDisplays - 1; i > -1; i--)
	{
		shiftData(numbersToShow[i]);
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