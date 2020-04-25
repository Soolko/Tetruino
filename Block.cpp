#include "Block.hpp"

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
