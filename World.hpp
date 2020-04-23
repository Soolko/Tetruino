#ifndef TETRUINO_WORLD_HPP
#define TETRUINO_WORLD_HPP

#include <FastLED.h>

namespace Tetruino
{
	class World
	{
	public:
		World(unsigned width, unsigned height);
		~World();
		
		// Bounds
		const unsigned width, height;
		const unsigned ledCount;
		
		// Actual world
		typedef CRGB WorldPixel;
		const WorldPixel BackgroundColour = WorldPixel { 0, 0, 0 };
		
		WorldPixel* world;
	};
}

#endif