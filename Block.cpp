#include "Block.hpp"
#include <Arduino.h>

using namespace Tetruino;

// Constructors
Block::Block
(
	const unsigned char size,
	const YAlignment yAlignment,
	const BoolArray& baseShape,
	const Colour colour
):
	size(size),
	yAlignment(yAlignment),
	shape(baseShape),
	colour(colour)
{
	calculateOffset();
}

Block::Block(const Block& other):
	size(other.size),
	yAlignment(other.yAlignment),
	shape(other.shape),
	colour(other.colour)
{
	calculateOffset();
}


// Translation/Rotation
void Block::rotateLeft()
{
	BoolArray output(size * size);
	
	for(unsigned char x = 0; x < size; x++)
	{
		for(unsigned char y = 0; y < size; y++)
		{
			const unsigned int newX = size - y - 1;
			const unsigned int newY = x;
			
			output.set((y * size) + x, shape.get((newY * size) + newX));
		}
	}
	
	// Copy array
	for(unsigned char i = 0; i < size * size; i++) shape.set(i, output.get(i));
	calculateOffset();
}

void Block::rotateRight()
{
	BoolArray output(size * size);
	
	for(unsigned char x = 0; x < size; x++)
	{
		for(unsigned char y = 0; y < size; y++)
		{
			const unsigned int newX = y;
			const unsigned int newY = size - x - 1;
			
			output.set((y * size) + x, shape.get((newY * size) + newX));
		}
	}
	
	// Copy array
	for(unsigned char i = 0; i < size * size; i++) shape.set(i, output.get(i));
	calculateOffset();
}

char Block::getOffsetX() const { return offsetX; }
char Block::getOffsetY() const { return offsetY; }

Block::Bounds Block::getBounds() const
{
	Bounds bounds { size, 0, size, 0 };
	
	// Find bounds of actual shape
	for(unsigned char y = 0; y < size; y++)
	for(unsigned char x = 0; x < size; x++)
	{
		if(shape.get(x + (y * size)))
		{
			if(bounds.minX > x) bounds.minX = x;
			if(bounds.maxX < x) bounds.maxX = x;
			if(bounds.minY > y) bounds.minY = y;
			if(bounds.maxY < y) bounds.maxY = y;
		}
	}
	
	return bounds;
}

void Block::calculateOffset()
{
	const Bounds bounds = getBounds();
	
	offsetX = -bounds.minX;
	switch(yAlignment)
	{
	default:
	case YAlignment::down:
		offsetY = size - (bounds.maxY + 1);
		break;
	case YAlignment::up:
		offsetY = -bounds.minY;
		break;
	}
}

/*
	Definitions
 */
using YAlignment = Tetruino::Block::YAlignment;

constexpr uint8_t IShapeRaw[] = { 0b00010001u, 0b00010001u };
const BoolArray IShape(16, IShapeRaw);
const Block Blocks::I = Block(4, YAlignment::up, IShape, Colour { 0, ColourBrightness, ColourBrightness });

constexpr uint8_t OShapeRaw[] = { 0b1111u };
const BoolArray OShape(4, OShapeRaw);
const Block Blocks::O = Block(2, YAlignment::down, OShape, Colour { ColourBrightness, ColourBrightness, 0 });

constexpr uint8_t TShapeRaw[] = { 0b00010111u, 0b0u };
const BoolArray TShape(9, TShapeRaw);
const Block Blocks::T = Block(3, YAlignment::up, TShape, Colour { ColourBrightness, 0, ColourBrightness });

constexpr uint8_t SShapeRaw[] = { 0b00011110u, 0b0u };
const BoolArray SShape(9, SShapeRaw);
const Block Blocks::S = Block(3, YAlignment::up, SShape, Colour { 0, ColourBrightness, 0 });

constexpr uint8_t ZShapeRaw[] = { 0b00110011u, 0b0u };
const BoolArray ZShape(9, ZShapeRaw);
const Block Blocks::Z = Block(3, YAlignment::up, ZShape, Colour { ColourBrightness, 0, 0 });

constexpr uint8_t JShapeRaw[] = { 0b00111001u, 0b0u };
const BoolArray JShape(9, JShapeRaw);
const Block Blocks::J = Block(3, YAlignment::up, JShape, Colour { 0, 0, ColourBrightness });

constexpr uint8_t LShapeRaw[] = { 0b00111100u, 0b0u };
const BoolArray LShape(9, LShapeRaw);
const Block Blocks::L = Block(3, YAlignment::up, LShape, { ColourBrightness, ColourBrightness / 4, 0 });
