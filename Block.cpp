#include "Block.hpp"
#include "Renderer.hpp"

using namespace Tetruino;

Block::Block
(
	unsigned char bounds,
	const bool* baseShape, Rotation baseRotation,
	const Colour& colour
) :
	bounds(bounds),
	rotation(baseRotation),
	colour(colour)
{
	shape = new bool[bounds * bounds];
	for(unsigned i = 0; i < bounds * bounds; i++) { shape[i] = baseShape[i]; }
}

Block::~Block()
{
	delete[] shape;
}

// Translation/Rotation
void Block::rotateLeft()
{
	bool* output = new bool[bounds * bounds];
	
	for(unsigned int x = 0; x < bounds; x++)
	{
		for(unsigned int y = 0; y < bounds; y++)
		{
			const unsigned int newX = bounds - y - 1;
			const unsigned int newY = x;
			
			output[(y * bounds) + x] = shape[(newY * bounds) + newX];
		}
	}
	
	*shape = *output;
	delete[] output;
	
	rotation = rotation.rotateLeft();
}

void Block::rotateRight()
{
	bool* output = new bool[bounds * bounds];
	
	for(unsigned int x = 0; x < bounds; x++)
	{
		for(unsigned int y = 0; y < bounds; y++)
		{
			const unsigned int newX = y;
			const unsigned int newY = bounds - x - 1;
			
			output[(y * bounds) + x] = shape[(newY * bounds) + newX];
		}
	}
	
	*shape = *output;
	delete[] output;
	
	rotation = rotation.rotateRight();
}
