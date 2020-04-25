#include "Renderer.hpp"
#include <FastLED.h>

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
	FastLED.addLeds<NEOPIXEL, 3>(buffer, bounds.getGridCount());
}

Renderer::~Renderer()
{
	delete[] buffer;
}

void Renderer::drawBlock(const Block& block, const int x, const int y)
{
	for(unsigned char blockY = 0; blockY < block.bounds; blockY++)
	for(unsigned char blockX = 0; blockX < block.bounds; blockX++)
	{
		// Next iteration if block doesn't exist at this point
		if(!block.shape[blockX + (blockY * block.bounds)]) continue;
		
		// Get final coord
		const int bufferX = blockX + x;
		const int bufferY = blockY + y;
		
		// Bounds checks
		if(bufferX < 0 || bufferY < 0) continue;
		if(bufferX >= bounds.width) continue;
		if(bufferY >= bounds.height) continue;
		
		// Set buffer
		buffer[bufferX + (bufferY * bounds.width)] = block.colour;
	}
}

void Renderer::draw()
{
	flipBuffer();
	FastLED.show();
}

void Renderer::clear()
{
	for(unsigned int i = 0; i < bounds.getGridCount(); i++)
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
	
	for(unsigned char y = 0; y < bounds.height; y++)
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
		for(unsigned char x = 0; x < bounds.width; x++)
		{
			row[bounds.width - x - 1] = buffer[x + (y * bounds.width)];
		}
		
		// Copy back
		for(unsigned char x = 0; x < bounds.width; x++)
		{
			buffer[x + (y * bounds.width)] = row[x];
		}
		delete[] row;
	}
}
