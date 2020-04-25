#include <Arduino.h>
#include <FastLED.h>

#include "Game.hpp"
#include "Bounds.hpp"
#include "Block.hpp"

using namespace Tetruino;

// Constants
constexpr Bounds bounds = { 8u, 32u };

// Objects
//Game game(bounds);

Renderer renderer(bounds);

void setup()
{
	// Random pin
	pinMode(A0, INPUT);
	randomSeed(digitalRead(A0));
}

Block block = Blocks::rightZ;

void loop()
{
	renderer.clear();
	
	renderer.drawBlock(block, 2, 2);
	
	renderer.draw();
	
	delay(500);
	
	block.rotateLeft();
}
