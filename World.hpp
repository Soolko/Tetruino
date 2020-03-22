#ifndef TETRUINO_WORLD_HPP
#define TETRUINO_WORLD_HPP

namespace Tetruino
{
	class World
	{
		World(unsigned width, unsigned height) : width(width), height(height) {}
		
		// Bounds
		const unsigned width, height;
		
		// Actual world
		rgb_color* world[];
	};
}

#endif