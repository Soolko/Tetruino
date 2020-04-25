#ifndef TETRUINO_WORLD_HPP
#define TETRUINO_WORLD_HPP

#include "Renderer.hpp"
#include "Bounds.hpp"
#include "Block.hpp"
#include "BoolArray.hpp"

namespace Tetruino
{
	class World
	{
	public:
		World(const Bounds& bounds, const Renderer& renderer);
		~World();
	protected:
		// Renderer object
		const Renderer* renderer;
		
		// World
		const Bounds bounds;
		BoolArray* collisionMap;
	private:
		const Block* randomBlock();
	};
}

#endif