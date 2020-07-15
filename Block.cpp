#include "Block.hpp"

using namespace Tetruino;

Block::Block(const unsigned char size, const YAlignment yAlignment, const BoolArray& shape, const Colour* colour, const int x, const int y):
	size(size), yAlignment(yAlignment), shape(shape), colour(colour), x(x), y(y)
{
	calculateOffset();
}

Block::Block(const Block& other):
	size(other.size), yAlignment(other.yAlignment), shape(other.shape), colour(other.colour), x(other.x), y(other.y)
{
	calculateOffset();
}

// Translation/Rotation
void Block::rotateLeft()
{
	BoolArray output(size * size);
	
	for(uint8_t x = 0; x < size; x++)
	for(uint8_t y = 0; y < size; y++)
	{
		const uint8_t newX = size - y - 1;
		const uint8_t newY = x;
		
		output.set((y * size) + x, shape.get((newY * size) + newX));
	}
	
	// Copy array
	shape.clear();
	for(uint8_t i = 0; i < size * size; i++) shape.set(i, output.get(i));
	calculateOffset();
}

void Block::rotateRight()
{
	BoolArray output(size * size);
	
	for(uint8_t x = 0; x < size; x++)
	for(uint8_t y = 0; y < size; y++)
	{
		const uint8_t newX = y;
		const uint8_t newY = size - x - 1;
		
		output.set((y * size) + x, shape.get((newY * size) + newX));
	}
	
	// Copy array
	shape.clear();
	for(uint8_t i = 0; i < size * size; i++) shape.set(i, output.get(i));
	calculateOffset();
}

Block::ShapeBounds Block::getBounds() const
{
	ShapeBounds bounds { size, 0, size, 0 };
	
	// Find bounds of actual shape
	for(uint8_t y = 0; y < size; y++)
	for(uint8_t x = 0; x < size; x++)
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
	const Block::ShapeBounds bounds = getBounds();
	
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

uint8_t Block::ShapeBounds::getWidth()	const { return (maxX - minX) + 1; }
uint8_t Block::ShapeBounds::getHeight()	const { return (maxY - minY) + 1; }

/*
	Definitions
 */
using YAlignment = Tetruino::Block::YAlignment;

constexpr uint8_t IShapeRaw[] = { 0b00001111u, 0b00000000u };
const BoolArray IShape(16, IShapeRaw);
const Colour IColour = Colour { 0, ColourBrightness, ColourBrightness };
const Block Blocks::I = Block(4, YAlignment::up, IShape, &IColour);

constexpr uint8_t OShapeRaw[] = { 0b1111u };
const BoolArray OShape(4, OShapeRaw);
const Colour OColour = Colour { ColourBrightness, ColourBrightness, 0 };
const Block Blocks::O = Block(2, YAlignment::down, OShape, &OColour);

constexpr uint8_t TShapeRaw[] = { 0b00010111u, 0b0u };
const BoolArray TShape(9, TShapeRaw);
const Colour TColour = Colour { ColourBrightness, 0, ColourBrightness };
const Block Blocks::T = Block(3, YAlignment::up, TShape, &TColour);

constexpr uint8_t SShapeRaw[] = { 0b00011110u, 0b0u };
const BoolArray SShape(9, SShapeRaw);
const Colour SColour = Colour { 0, ColourBrightness, 0 };
const Block Blocks::S = Block(3, YAlignment::up, SShape, &SColour);

constexpr uint8_t ZShapeRaw[] = { 0b00110011u, 0b0u };
const BoolArray ZShape(9, ZShapeRaw);
const Colour ZColour = Colour { ColourBrightness, 0, 0 };
const Block Blocks::Z = Block(3, YAlignment::up, ZShape, &ZColour);

constexpr uint8_t JShapeRaw[] = { 0b00111001u, 0b0u };
const BoolArray JShape(9, JShapeRaw);
const Colour JColour = Colour { 0, 0, ColourBrightness };
const Block Blocks::J = Block(3, YAlignment::up, JShape, &JColour);

constexpr uint8_t LShapeRaw[] = { 0b00111100u, 0b0u };
const BoolArray LShape(9, LShapeRaw);
const Colour LColour = { ColourBrightness, ColourBrightness / 4, 0 };
const Block Blocks::L = Block(3, YAlignment::up, LShape, &LColour);
