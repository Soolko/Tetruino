#ifndef TETRUINO_WORLD_HPP
#define TETRUINO_WORLD_HPP

#include "Renderer.hpp"
#include "Bounds.hpp"
#include "Block.hpp"
#include "BoolArray.hpp"
#include "Vector.hpp"

namespace Tetruino
{
	class World final
	{
	public:
		World(const Bounds& bounds) : bounds(bounds), collisionMap(bounds.getGridCount()) {}
		~World();
		
		// Public vars
		const Bounds bounds;
		
		// Methods
		void addBlock(const Block& block);
		
		// Getters
		const BoolArray& getCollisionMap() const;
		const Vector<Block>& getBlocks() const;
	private:
		BoolArray collisionMap;
		Vector<Block>* blocks;
	};
}

#endif