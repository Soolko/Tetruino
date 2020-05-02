#include <Arduino.h>
#include <FastLED.h>

#include "Game.hpp"
#include "Bounds.hpp"

using namespace Tetruino;

Game gameInstance(Bounds { 8, 32 });

void setup()
{
	gameInstance.setup();
}

void loop()
{
	gameInstance.loop();
}
