#ifndef TETRUINO_FALLINGBLOCK_HPP
#define TETRUINO_FALLINGBLOCK_HPP

#include "Block.hpp"
#include "World.hpp"

namespace Tetruino
{
	class FallingBlock : public Block
	{
	public:
		// Constructors
		FallingBlock(const World& world, const Block other) : Block(other), world(&world), x(world.bounds.width / 2), y(0) {}
		FallingBlock
		(
			// Block
			unsigned char size,
			const BoolArray& baseShape,
			const Colour& colour,
			Rotation baseRotation,
			
			// FallingBlock
			const World* world
		) : Block(size, baseShape, colour, baseRotation),	/* Block */
			world(world), x(world->bounds.width / 2), y(0)	/* FallingBlock */ {}
		
		/* 
		 * Set position, returns true if colliding with something now.
		 */
		bool setPosition(int x, int y);
		int getX() const; int getY() const;
		
		bool isColliding() const;
	protected:
		// Vars
		int x, y;
	private:
		// References
		const World* world;
	};
}

#endif