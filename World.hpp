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
		
		enum class CollisionStatus : uint8_t
		{
			none	= 0b0000,
			bottom	= 0b0001,
			top		= 0b0010,	// wtf?
			left	= 0b0100,
			right	= 0b1000
		};
		
		void addBlock(const Block& block);
		uint8_t isColliding(const Block& block) const;
	};
}

#endif