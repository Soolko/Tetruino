#include "Renderer.hpp"
#include <FastLED.h>

using namespace Tetruino;

Renderer::Renderer(const World& world) : world(world)
{
	
}

void Renderer::setup()
{
	FastLED.addLeds<NEOPIXEL, 3>(world.world, world.ledCount);
}

void Renderer::loop()
{
	FastLED.show();
	delay(500);
}
