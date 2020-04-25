#include <Arduino.h>
#include <FastLED.h>

#include "Game.hpp"
#include "Bounds.hpp"
#include "Block.hpp"

using namespace Tetruino;

#include <MemoryFree.h>

Game game(Bounds { 8, 32 });

void setup()
{
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
	game.loop();
}
