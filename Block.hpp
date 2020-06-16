#ifndef TETRUINO_BLOCK_HPP
#define TETRUINO_BLOCK_HPP

#include "Colour.hpp"
#include "BoolArray.hpp"

namespace Tetruino
{
	struct Block
	{
		enum class YAlignment : int8_t { up = 1, down = -1 };
		
		Block(unsigned char size, YAlignment yAlignment, const BoolArray& shape, const Colour* colour, int x = 0, int y = 0);
		Block(const Block& other);
		
		const uint8_t size;
		const YAlignment yAlignment;
		
		BoolArray shape;
		const Colour* colour;
		
		struct ShapeBounds
		{
			uint8_t minX; uint8_t maxX;
			uint8_t minY; uint8_t maxY;
			
			uint8_t getWidth() const;
			uint8_t getHeight() const;
		};
		Block::ShapeBounds getBounds() const;
		
		int x, y;
		int8_t offsetX, offsetY;
		
		void rotateLeft();
		void rotateRight();
	private:
		void calculateOffset();
	};
	
	namespace Blocks
	{
		static constexpr uint8_t blockCount = 7;
		
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