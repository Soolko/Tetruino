#include "Renderer.hpp"
#include <FastLED.h>

#include <Arduino.h>

using namespace Tetruino;

// Set pin here
constexpr uint8_t OutputPin = 3;
#define FLIP_EVEN

Renderer::Renderer(const Bounds& bounds) : bounds(bounds)
{
	buffer = new Colour[bounds.getGridCount()];
	
	/*
	 * This is required to set the memory,
	 * to avoid the previous block before this was allocated being read.
	 */
	clear();
	FastLED.addLeds<LEDType, OutputPin>(buffer, bounds.getGridCount());
}

Renderer::~Renderer()
{
	delete[] buffer;
}

void Renderer::drawPixel(int x, int y, const Colour colour)
{
	if(x < 0 || x > bounds.width) return;
	if(y < 0 || y > bounds.height) return;
	buffer[x + (y * bounds.width)] = colour;
}

void Renderer::drawBlock
(
	const Block& block,
	const int x, const int y,
	const bool customColour, const Colour colour,
	const bool additive
)
{
	for(uint8_t blockY = 0; blockY < block.size; blockY++)
	for(uint8_t blockX = 0; blockX < block.size; blockX++)
	{
		// Next iteration if block doesn't exist at this point
		if(!block.shape.get(blockX + (blockY * block.size))) continue;
		
		// Get final coords
		const int bufferX = blockX + x + block.offsetX;
		const int bufferY = blockY + y + block.offsetY;
		
		// Bounds checks
		if(bufferX < 0 || bufferY < 0) continue;
		if(bufferX >= bounds.width) continue;
		if(bufferY >= bounds.height) continue;
		
		// Set buffer
		const int bufferIndex = bufferX + (bufferY * bounds.width);
		if(bufferIndex > (int) bounds.getGridCount()) return;
		
		const Colour finalColour = customColour ? colour : *(block.colour);
		if(!additive) buffer[bufferIndex] = finalColour;
		else
		{
			Colour oldColour = buffer[bufferIndex];
			oldColour.r += finalColour.r;
			oldColour.g += finalColour.g;
			oldColour.b += finalColour.b;
			buffer[bufferIndex] = oldColour;
		}
	}
}

void Renderer::drawMap(const Colour** map, const Bounds& bounds)
{
	for(unsigned short i = 0; i < bounds.getGridCount(); i++)
	{
		// Avoid buffer overflow
		if(map[i] != nullptr) buffer[i] = *map[i];
	}
}

void Renderer::draw()
{
	flipBuffer();
	FastLED.show();
}

void Renderer::clear()
{
	for(unsigned short i = 0; i < bounds.getGridCount(); i++)
	{
		// Set buffer to all black.
		buffer[i] = Colour { 0, 0, 0 };
	}
}

void Renderer::flipBuffer()
{
	#if !(defined(FLIP_EVEN) || defined(FLIP_ODD))
	return;
	#endif
	
	for(uint8_t y = 0; y < bounds.height; y++)
	{
		bool flip = false;
		
		#ifdef FLIP_EVEN
		flip |= y % 2 == 0;
		#endif
		
		#ifdef FLIP_ODD
		flip |= y % 2 == 1;
		#endif
		
		// If it doesn't need to flip, iterate to the next time
		if(!flip) continue;
		
		// Copy line to new array flipped
		Colour* row = new Colour[bounds.width];
		for(uint8_t x = 0; x < bounds.width; x++)
		{
			row[bounds.width - x - 1] = buffer[x + (y * bounds.width)];
		}
		
		// Copy back
		for(uint8_t x = 0; x < bounds.width; x++)
		{
			buffer[x + (y * bounds.width)] = row[x];
		}
		delete[] row;
	}
}
