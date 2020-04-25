#include "Block.hpp"
#include <Arduino.h>
using namespace Tetruino;

Block::Block
(
	unsigned char size,
	const BoolArray& baseShape,
	const Colour& colour,
	Rotation baseRotation
) :
	size(size),
	colour(colour),
	shape(baseShape),
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
	
	// Copy array
	for(unsigned char i = 0; i < size * size; i++) shape.set(i, output.get(i));
	
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
	
	// Copy array
	for(unsigned char i = 0; i < size * size; i++) shape.set(i, output.get(i));
	
	rotation = rotation.rotateRight();
}
