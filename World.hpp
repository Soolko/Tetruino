#ifndef TETRUINO_WORLD_HPP
#define TETRUINO_WORLD_HPP

#include "Block.hpp"
#include "Renderer.hpp"
#include "Colour.hpp"
#include "Bounds.hpp"

namespace Tetruino
{
	class World
	{
	public:
		World(const Bounds& bounds, const Renderer& renderer);
		
		// Getters
		const Block* getCurrentBlock();
		const Block* getNextBlock();
	protected:
		// Renderer object
		const Renderer* renderer;
		
		// World bounds
		const Bounds bounds;
		
		// Current block
		Block* currentBlock;
		int x = xDefault, y = yDefault;
		
		// Next block
		Block* nextBlock;
	private:
		const int xDefault = bounds.width / 2;
		const int yDefault = 0;
		
		const Block* randomBlock();
	};
}

#endif