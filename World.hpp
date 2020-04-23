#ifndef TETRUINO_WORLD_HPP
#define TETRUINO_WORLD_HPP

#include "Block.hpp"
#include "Renderer.hpp"

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
		
		const Colour BackgroundColour = Colour { 0, 0, 0 };
		Colour* world;
	private:
		const int xDefault = width / 2;
		const int yDefault = 0;
	protected:
		const Block* currentBlock;
		int x = xDefault, y = yDefault;
	};
}

#endif