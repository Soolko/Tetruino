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

bool World::hitBottom(const Block& block)
{
	const Block::ShapeBounds blockBounds = block.getBounds();
	
	for(short y = block.size - 1; y >= 0; y--)
	for(unsigned char x = 0; x <= block.size; x++)
	{
		// This part of the block exists
		if(block.shape.get(x + (y * block.size)))
		{
			const int worldX = block.x + block.offsetX + x;
			const int worldY = block.y + block.offsetY + y + 1;
			const int index = worldX + (worldY * bounds.width);
			
			// Bounds check
			if(worldX < 0) continue;
			if(worldY < 0) continue;
			if(worldX >= bounds.width) continue;
			if(worldY >= bounds.height) return true;
			
			// Actual block check
			if(blockMap[index] != nullptr) return true;
		}
	}
	return false;
}
