#ifndef TETRUINO_WORLD_HPP
#define TETRUINO_WORLD_HPP

#include "Block.hpp"
#include "Colour.hpp"

namespace Tetruino
{
	class World
	{
	public:
		World(unsigned width, unsigned height);
		
		// Getters
		const Block* getCurrentBlock();
		const Block* getNextBlock();
		
		// Bounds
		const unsigned width, height;
		const unsigned ledCount;
	protected:
		// Current block
		Block* currentBlock;
		int x = xDefault, y = yDefault;
		
		// Next block
		Block* nextBlock;
	private:
		bool* collisionMap;
		
		const int xDefault = width / 2;
		const int yDefault = 0;
	};
}

#endif