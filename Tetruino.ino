#include <Arduino.h>
#include <FastLED.h>

#include "Game.hpp"
#include "Bounds.hpp"
#include "Block.hpp"

using namespace Tetruino;

Game game(Bounds { 8, 32 });

void setup()
{
	game.setup();
}

void loop()
{
	game.loop();
}
