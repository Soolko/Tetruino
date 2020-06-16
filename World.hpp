#ifndef TETRUINO_WORLD_HPP
#define TETURINO_WORLD_HPP

#include "Block.hpp"
#include "Bounds.hpp"

#include <Arduino.h>

namespace Tetruino
{
	struct World final
	{
	public:
		World(const Bounds& bounds);
		~World();
		
		const Bounds bounds;
		const Colour** blockMap;
		
		void addBlock(const Block& block);
		
		void clearLine(uint8_t line);
		size_t checkLines(uint8_t* lines);
		
		bool hitBottom(const Block& block);
	};
}

#endif