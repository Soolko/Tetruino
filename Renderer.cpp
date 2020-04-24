#include "Renderer.hpp"
#include <FastLED.h>

using namespace Tetruino;

// Set pin here
constexpr uint8_t OutputPin = 3;
#define FLIP_ODD

Renderer::Renderer(const Bounds& bounds) : bounds(bounds)
{
	buffer = new Colour[bounds.getGridCount()];
	
	/*
	 * This is required to set the memory,
	 * to avoid the previous block before this was allocated being read.
	 */
	clear();
}

Renderer::~Renderer()
{
	delete[] buffer;
}

void Renderer::setup()
{
	FastLED.addLeds<NEOPIXEL, 3>(buffer, bounds.getGridCount());
}

void Renderer::loop()
{
	FastLED.show();
}

void Renderer::addBlock(const Block& block, const int x, const int y)
{
	for(int shapeY = 0; shapeY < block.bounds; shapeY++)
	{
		for(int shapeX = 0; shapeX < block.bounds; shapeX++)
		{
			const int shapeIndex = shapeX + (shapeY * block.bounds);
			if(block.shape[shapeIndex])
			{
				int bufferX = x + shapeX;
				int bufferY = y + shapeY;
				
				#ifdef FLIP_ODD
				if(bufferY % 2 == 1) bufferX = bounds.width - bufferX - 1;
				#endif
				
				const int bufferIndex = bufferX + (bufferY * bounds.width);
				if(bufferIndex >= 0) buffer[bufferIndex] = block.colour;
			}
		}
	}
}

void Renderer::clear()
{
	for(unsigned int i = 0; i < bounds.getGridCount(); i++)
	{
		// Set buffer to all black.
		buffer[i] = Colour { 0, 0, 0 };
	}
}
