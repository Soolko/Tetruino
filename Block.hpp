#ifndef TETRUINO_BLOCK_HPP
#define TETRUINO_BLOCK_HPP

#include "Rotation.hpp"
#include "Colour.hpp"

namespace Tetruino
{
	class Block
	{
	public:
		Block
		(
			unsigned char bounds,
			const bool* baseShape, Rotation baseRotation,
			const Colour& colour
		);
		~Block();
		
		const Colour& colour;
		
		// The width or height of the shape. Width == Height.
		const unsigned char bounds;
		
		bool* shape;
		Rotation rotation;
		
		void rotateLeft();
		void rotateRight();
	};
}

#endif