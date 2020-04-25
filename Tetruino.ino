#include <Arduino.h>
#include <FastLED.h>

#include "Game.hpp"
#include "Bounds.hpp"
#include "Block.hpp"

using namespace Tetruino;

// Objects
Game game(Bounds { 8u, 32u });

void setup()
{
	// Random pin
	pinMode(A0, INPUT);
	randomSeed(digitalRead(A0));
	
	game.setup();
}

void loop()
{
	game.loop();
}
