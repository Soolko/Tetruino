#include "Block.hpp"

using namespace Tetruino;

Block::Block
(
	unsigned char bounds,
	bool baseShape[], Rotation baseRotation,
	const rgb_color& colour
) :
	bounds(bounds),
	rotation(baseRotation),
	colour(colour)
{
	*shape = baseShape;
}

// Getters
const bool& Block::getShape() const { return *shape; }
Rotation Block::getRotation() const { return rotation; }

// Translation/Rotation
void Block::rotateLeft()
{
	bool output[bounds * bounds];
	
	for(unsigned int x = 0; x < bounds; x++)
	{
		for(unsigned int y = 0; y < bounds; y++)
		{
			const unsigned int newX = bounds - y - 1;
			const unsigned int newY = x;
			
			output[(y * bounds) + x] = shape[(newY * bounds) + newX];
		}
	}
	
	*shape = output;
	rotation = rotation.rotateLeft();
}

void Block::rotateRight()
{
	bool output[bounds * bounds];
	
	for(unsigned int x = 0; x < bounds; x++)
	{
		for(unsigned int y = 0; y < bounds; y++)
		{
			const unsigned int newX = y;
			const unsigned int newY = bounds - x - 1;
			
			output[(y * bounds) + x] = shape[(newY * bounds) + newX];
		}
	}
	
	*shape = output;
	rotation = rotation.rotateRight();
}
