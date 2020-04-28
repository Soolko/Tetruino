#ifndef TETRUINO_BLOCK_HPP
#define TETRUINO_BLOCK_HPP

#include "BoolArray.hpp"
#include "Colour.hpp"

namespace Tetruino
{
	class Block
	{
	public:
		enum class YAlignment : char { up = 1, down = -1 };
		
		Block(unsigned char size, YAlignment yAlignment, const BoolArray& baseShape, const Colour colour);
		Block(const Block& other);
		
		const unsigned char size;
		const Colour colour;
		BoolArray shape;
		
		void rotateLeft();
		void rotateRight();
		
		struct Bounds
		{
			unsigned char minX; unsigned char maxX;
			unsigned char minY; unsigned char maxY;
		};
		Bounds getBounds() const;
		
		char getOffsetX() const; char getOffsetY() const;
	protected:
		const YAlignment yAlignment;
		char offsetX, offsetY;
		
		void calculateOffset();
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