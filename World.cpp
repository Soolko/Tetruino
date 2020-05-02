#include "World.hpp"

using namespace Tetruino;

World::~World()
{
	if(blocks != nullptr) delete blocks;
}

void World::addBlock(const Block block)
{
	const BlockEntry entry
	{
		block.colour,
		block.shape,
		block.x, block.y
	};
	
	if(blocks != nullptr) blocks->add(entry);
	else blocks = new Vector<BlockEntry>(entry);
}

/* 
 * Like all collision code, this is an absolute mess.
 */
uint8_t World::isColliding(const Block& block) const
{
	const Block::ShapeBounds blockBounds = block.getBounds();
	
	bool left = false;
	bool right = false;
	bool top = false;
	bool bottom = false;
	
	// Quick side checks
	if((char) blockBounds.minX - 1 < 0) left = true;
	if((char) blockBounds.minY - 1 < 0) top = true;
	if((short) blockBounds.maxX + 1 >= bounds.width) right = true;
	if((short) blockBounds.maxY + 1 >= bounds.height) bottom = true;
	
	/*
		In-depth collision map check
	 */
	for(unsigned char shapeY = blockBounds.minY; shapeY <= blockBounds.maxY; shapeY++)
	for(unsigned char shapeX = blockBounds.minX; shapeX <= blockBounds.maxX; shapeX++)
	{
		// Continue if shape is not at position
		if(!block.shape.get(shapeX + (shapeY * block.size))) continue;
		
		int worldX = block.x + block.offsetX + shapeX;
		int worldY = block.y + block.offsetY + shapeY;
		
		// Left
		if(shapeX == blockBounds.minX)
		{
			worldX--;
			
			if(worldX < 0) goto leftCheckEnd;
			if(collisionMap.get(worldX + (worldY * bounds.width)))
			{
				// Hit a block to the left
				left = true;
			}
			
		leftCheckEnd:
			worldX++;
		}
		
		// Right
		if(shapeX == blockBounds.maxX)
		{
			worldX++;
			
			if(worldX > bounds.width) goto rightCheckEnd;
			if(collisionMap.get(worldX + (worldY * bounds.width)))
			{
				// Hit a block to the right
				right = true;
			}
			
		rightCheckEnd:
			worldX--;
		}
		
		// Down
		if(shapeY == blockBounds.maxY)
		{
			worldY++;
			
			if(worldY > bounds.height) goto downCheckEnd;
			if(collisionMap.get(worldX + (worldY * bounds.width)))
			{
				// Hit a block downwards
				bottom = true;
			}
			
		downCheckEnd:
			worldY--;
		}
	}
	
	// Combine into bitmask
	uint8_t output = 0;
	if(!(left || right || top || bottom)) output = (uint8_t) CollisionStatus::none;
	else
	{
		if(left)	output += (uint8_t) CollisionStatus::left;
		if(right)	output += (uint8_t) CollisionStatus::right;
		if(top)		output += (uint8_t) CollisionStatus::top;
		if(bottom)	output += (uint8_t) CollisionStatus::bottom;
	}
	
	return output;
}
