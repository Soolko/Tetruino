#include <Arduino.h>
#include <FastLED.h>

#include "Game.hpp"
#include "Bounds.hpp"

using namespace Tetruino;

// Constants
constexpr Bounds bounds = { 8u, 32u };

// Objects
//Game game(bounds);

Renderer renderer(bounds);

void setup()
{
	renderer.setup();
	
	bool blockShape[] = { true, true, true, true };
	Colour blockColour = { 10, 10, 0 };
	
	Block block(2u, blockShape, Rotation::up, blockColour);
	renderer.addBlock(block, 0, 0);
}

void loop()
{
	//game.loop();
	renderer.loop();
}
