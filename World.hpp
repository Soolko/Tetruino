#ifndef TETRUINO_WORLD_HPP
#define TETURINO_WORLD_HPP

#include "Block.hpp"
#include "Bounds.hpp"
#include "Vector.hpp"

#include <Arduino.h>

namespace Tetruino
{
	struct World final
	{
	public:
		World(const Bounds& bounds) : bounds(bounds), collisionMap(bounds.getGridCount()), blocks(nullptr) {}
		~World();
		
		Vector<Block>* blocks;
		void addBlock(const Block& block);
		
		enum class CollisionStatus : uint8_t
		{
			none	= 0b0000,
			bottom	= 0b0001,
			top		= 0b0010,	// wtf?
			left	= 0b0100,
			right	= 0b1000
		};
		
		const Bounds bounds;
		uint8_t isColliding(const Block& block) const;
	private:
		BoolArray collisionMap;
	};
}

#endif