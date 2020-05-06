#include "World.hpp"

using namespace Tetruino;

World::World(const Bounds& bounds) : bounds(bounds)
{
	blockMap = new const Colour*[bounds.getGridCount()];
	for(unsigned short i = 0; i < bounds.getGridCount(); i++) blockMap[i] = nullptr;
}

World::~World()
{
	delete[] blockMap;
}

void World::addBlock(const Block& block)
{
	const int blockPosX = block.x + block.offsetX;
	const int blockPosY = block.y + block.offsetY;
	
	// Add to world map
	for(unsigned char blockX = 0; blockX < block.size; blockX++)
	for(unsigned char blockY = 0; blockY < block.size; blockY++)
	{
		if(block.shape.get(blockX + (blockY * block.size)))
		{
			const unsigned char collisionX = (blockPosX + blockX);
			const unsigned char collisionY = (blockPosY + blockY);
			if(collisionX > bounds.width) continue;
			if(collisionY > bounds.height) continue;
			
			blockMap[collisionX + (collisionY * bounds.width)] = block.colour;
		}
	}
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
	if(block.x + (char) blockBounds.minX - 1 < 0) left = true;
	if(block.y + (char) blockBounds.minY - 1 < 0) top = true;
	if(block.x + (short) blockBounds.maxX + 1 >= bounds.width) right = true;
	if(block.y + (short) blockBounds.maxY + 1 >= bounds.height) bottom = true;
	
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
		
		// Down
		if(blockMap[shapeX + (shapeY - 1) * bounds.width] == nullptr) bottom = true;
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
