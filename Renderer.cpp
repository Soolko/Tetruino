#include "Renderer.hpp"
#include <FastLED.h>

using namespace Tetruino;


Renderer::Renderer(const World& world) : world(world)
{
	buffer = new Colour[world.ledCount];
}

Renderer::~Renderer()
{
	delete[] buffer;
}

void Renderer::setup()
{
	FastLED.addLeds<NEOPIXEL, 3>(buffer, world.ledCount);
}

void Renderer::loop()
{
	FastLED.show();
}
