#ifndef TETRUINO_FALLINGBLOCK_HPP
#define TETRUINO_FALLINGBLOCK_HPP

#include "Block.hpp"
#include "World.hpp"

#include <Arduino.h>

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
			YAlignment yAlignment,
			const BoolArray& baseShape,
			const Colour& colour,
			
			// FallingBlock
			const World* world
		) : Block(size, yAlignment, baseShape, colour),	/* Block */
			world(world), x(world->bounds.width / 2), y(0)	/* FallingBlock */ {}
		
		/* 
		 * Set position, returns true if colliding with something now.
		 */
		bool setPosition(int x, int y);
		int getX() const; int getY() const;
		
		enum class CollisionStatus : uint8_t
		{
			none	= 0b0000,
			bottom	= 0b0001,
			top		= 0b0010,	// wtf?
			left	= 0b0100,
			right	= 0b1000
		};
		
		uint8_t isColliding() const;
	protected:
		// Vars
		int x, y;
	private:
		// References
		const World* world;
	};
}

#endif