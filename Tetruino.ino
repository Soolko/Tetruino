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

const bool blockShape[] = { true, true, false, true };
const Colour blockColour = { 10, 20, 0 };
Block block(2u, blockShape, Rotation::up, blockColour);

void setup()
{
	
}

int x = 0;
int y = 0;

void loop()
{
	renderer.clear();
	renderer.addBlock(block, x, y);
	renderer.draw();
	
	delay(500);
	if(++x >= bounds.width) x = 0;
	if(++y >= bounds.height) y = 0;
}
