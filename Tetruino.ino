#include <Arduino.h>
#include <FastLED.h>

#include "Game.hpp"
#include "Bounds.hpp"
#include "Block.hpp"

using namespace Tetruino;

Game game(Bounds { 8, 32 });

void setup()
{
	Serial.begin(9600);
	
	for(unsigned char i = 0; i < 16; i++)
	{
		Serial.print(Blocks::IShape.get(i));
	}
	
	// Random pin
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(A0, INPUT);
	randomSeed(digitalRead(A0));
	
	game.setup();
}

bool crashLEDState = false;
void loop()
{
	// Crash check LED
	digitalWrite(LED_BUILTIN, crashLEDState);
	crashLEDState = !crashLEDState;
	
	delay(500);
	//game.loop();
	
	
}
