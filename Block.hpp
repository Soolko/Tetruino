#ifndef TETRUINO_BLOCK_HPP
#define TETRUINO_BLOCK_HPP

#include "BoolArray.hpp"
#include "Colour.hpp"
#include "Rotation.hpp"

namespace Tetruino
{
	class Block
	{
	public:
		Block
		(
			unsigned char size,
			const BoolArray baseShape, Rotation baseRotation,
			const Colour& colour
		);
		
		const unsigned char size;
		const Colour colour;
		
		BoolArray shape;
		Rotation rotation;
		
		void rotateLeft();
		void rotateRight();
	};
	
	namespace Blocks
	{
		static Block makeI();
		static Block makeO();
		static Block makeT();
		static Block makeS();
		static Block makeZ();
		static Block makeJ();
		static Block makeL();
	};
}

#endif
