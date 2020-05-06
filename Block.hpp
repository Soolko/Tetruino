#ifndef TETRUINO_BLOCK_HPP
#define TETRUINO_BLOCK_HPP

#include "Colour.hpp"
#include "BoolArray.hpp"

namespace Tetruino
{
	struct Block
	{
		enum class YAlignment : char { up = 1, down = -1 };
		
		Block(unsigned char size, YAlignment yAlignment, const BoolArray& shape, const Colour* colour, int x = 0, int y = 0);
		Block(const Block& other);
		
		const unsigned char size;
		const YAlignment yAlignment;
		
		BoolArray shape;
		const Colour* colour;
		
		struct ShapeBounds
		{
			unsigned char minX; unsigned char maxX;
			unsigned char minY; unsigned char maxY;
			
			unsigned char getWidth();
			unsigned char getHeight();
		};
		ShapeBounds getBounds() const;
		
		int x, y;
		char offsetX, offsetY;
		
		void rotateLeft();
		void rotateRight();
	private:
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