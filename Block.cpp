#include "Block.hpp"
#include "Renderer.hpp"

using namespace Tetruino;

Block::Block
(
	unsigned char size,
	const BoolArray baseShape, Rotation baseRotation,
	const Colour& colour
) :
	size(size),
	colour(colour),
	shape(shape),
	rotation(baseRotation)
{
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
	
	shape = output;
	rotation = rotation.rotateLeft();
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
	
	shape = output;
	rotation = rotation.rotateRight();
}

/* 
 *   BLOCK BUILDER METHODS
 */

// Builders
const Block& Blocks::makeI()
{
	BoolArray shape(16);
	for(unsigned char i = 4; i < 8; i++) shape.set(i, true);
	
	return Block
	(
		4,
		shape,
		Rotation::up,
		Colour { 0, ColourBrightness, ColourBrightness }
	);
}

const Block& Blocks::makeO()
{
	BoolArray shape(4);
	for(unsigned char i = 0; i < 4; i++) shape.set(i, true);
	
	return Block
	(
		2,
		shape,
		Rotation::up,
		Colour { ColourBrightness, ColourBrightness, 0 }
	);
}

const Block& Blocks::makeT()
{
	BoolArray shape(9);
	shape.set(4, true);
	shape.set(6, true);
	shape.set(7, true);
	shape.set(8, true);
	
	return Block
	(
		3,
		shape,
		Rotation::up,
		Colour { ColourBrightness, 0, ColourBrightness }
	);
}

const Block& Blocks::makeS()
{
	BoolArray shape(9);
	for(unsigned char i = 4; i <= 7; i++) shape.set(i, true);
	
	return Block
	(
		3,
		shape,
		Rotation::up,
		Colour { 0, ColourBrightness, 0 }
	);
}

const Block& Blocks::makeZ()
{
	BoolArray shape(9);
	shape.set(3, true);
	shape.set(4, true);
	shape.set(7, true);
	shape.set(8, true);
	
	return Block
	(
		3,
		shape,
		Rotation::up,
		Colour { ColourBrightness, 0, 0 }
	);
}

const Block& Blocks::makeJ()
{
	BoolArray shape(9);
	shape.set(3, true);
	for(unsigned char i = 6; i <= 8; i++) shape.set(i, true);
	
	return Block
	(
		3,
		shape,
		Rotation::up,
		Colour { 0, 0, ColourBrightness }
	);
}

const Block& Blocks::makeL()
{
	BoolArray shape(9);
	for(unsigned char i = 5; i <= 8; i++) shape.set(i, true);
	
	return Block
	(
		3,
		shape,
		Rotation::up,
		Colour { ColourBrightness, ColourBrightness / 4, 0 }
	);
}
