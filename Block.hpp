#ifndef TETRUINO_BLOCK_HPP
#define TETRUINO_BLOCK_HPP

#include "BoolArray.hpp"
#include "Colour.hpp"

namespace Tetruino
{
	class Block
	{
	public:
		Block(unsigned char size, const BoolArray& baseShape, const Colour colour);
		Block(const Block& other);
		
		const unsigned char size;
		const Colour colour;
		BoolArray shape;
		
		void rotateLeft();
		void rotateRight();
		
		char getOffsetX() const; char getOffsetY() const;
	protected:
		void calculateOffset();
		char offsetX, offsetY;
	};
	
	namespace Blocks
	{
		static constexpr unsigned char blockCount = 7;
		
		extern const Block I;
		extern const Block O;
		extern const Block T;
		extern const Block S;
		extern const Block Z;
		extern const Block J;
		extern const Block L;
	};
}

#endif