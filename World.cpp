#include "World.hpp"
#include "Vector.hpp"

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
	for(uint8_t blockX = 0; blockX < block.size; blockX++)
	for(uint8_t blockY = 0; blockY < block.size; blockY++)
	{
		if(block.shape.get(blockX + (blockY * block.size)))
		{
			const uint8_t collisionX = (blockPosX + blockX);
			const uint8_t collisionY = (blockPosY + blockY);
			if(collisionX > bounds.width) continue;
			if(collisionY > bounds.height) continue;
			
			blockMap[collisionX + (collisionY * bounds.width)] = block.colour;
		}
	}
}

Vector<uint8_t>* World::checkLines()
{
	// Store the lines
	Vector<uint8_t>* vector = nullptr;
	
	for(short y = bounds.height - 1; y >= 0; y--)
	{
		// Count the amount of squares taken in the current line
		uint8_t hitCount = 0;
		for(uint8_t x = 0; x < bounds.width; x++)
		{
			if(blockMap[x + (y * bounds.width)] != nullptr) hitCount += 1;
		}
		
		// Nothing hit, therefore there can't be anything above here,
		// so we can exit out of the loop.
		if(hitCount == 0) break;
		
		// This line is full, add it to the vector.
		if(hitCount == bounds.width)
		{
			if(vector == nullptr)
			{
				// If vector not initialised, initialise it.
				vector = new Vector<uint8_t>(y);
			}
			else	// Vector initialised
			{
				// Go to end of vector
				auto* current = vector;
				while(current->next != nullptr) current = vector->next;
				
				// Add to vector
				current->next = new Vector<uint8_t>(y);
			}
		}
	}
	
	return vector;
}

void World::clearLine(const uint8_t line)
{
	for(int16_t y = line; y >= 0; y--)
	{
		// Clear instead of doing the swap,
		// as there's nothing to swap down.
		if(y == 0)
		{
			for(uint8_t x = 0; x < bounds.width; x++)
			{
				blockMap[x + (y * bounds.width)] = nullptr;
			}
			return;
		}
		
		// Move everything down
		uint8_t blocksHit = 0;
		for(uint8_t x = 0; x < bounds.width; x++)
		{
			const uint16_t index = x + (y * bounds.width);
			const uint16_t nextIndex = x + ((y - 1) * bounds.width);
			
			if(blockMap[index] != nullptr) blocksHit++;
			blockMap[index] = blockMap[nextIndex];
		}
		
		// Exit if we hit a row with nothing
		if(blocksHit == 0) return;
	}
}

bool World::hitBottom(const Block& block)
{
	for(int16_t y = block.size - 1; y >= 0; y--)
	for(uint8_t x = 0; x <= block.size; x++)
	{
		// If this part of the block doesn't exist, carry on until it does
		if(!block.shape.get(x + (y * block.size))) continue;
		
		// Actual position
		const int worldX = block.x + block.offsetX + x;
		const int worldY = block.y + block.offsetY + y + 1;
		
		// Bounds check
		if(worldX < 0) continue;
		if(worldY < 0) continue;
		if(worldX >= bounds.width) continue;
		if(worldY >= bounds.height) return true;
		
		// Actual block check
		if(blockMap[worldX + (worldY * bounds.width)] != nullptr) return true;
	}
	return false;
}

bool World::hitLeft(const Block& block)
{
	for(uint8_t x = 0; x <= block.size; x++)
	for(uint8_t y = 0; y <= block.size; y++)
	{
		// If this part of the block doesn't exist, carry on until it does
		if(!block.shape.get(x + (y * block.size))) continue;
		
		// Actual position
		const int worldX = block.x + block.offsetX + x - 1;
		const int worldY = block.y + block.offsetY + y;
		
		// Bounds checks
		if(worldX < 0) return true;
		if(worldY < 0) continue;
		if(worldX >= bounds.width) return false;
		if(worldY >= bounds.height) continue;
		
		// Block check
		if(blockMap[worldX + (worldY * bounds.width)] != nullptr) return true;
	}
	return false;
}

bool World::hitRight(const Block& block)
{
	for(int16_t x = block.size - 1; x >= 0; x--)
	for(uint8_t y = 0; y <= block.size; y++)
	{
		// If this part of the block doesn't exist, carry on until it does
		if(!block.shape.get(x + (y * block.size))) continue;
		
		// Actual position
		const int worldX = block.x + block.offsetX + x + 1;
		const int worldY = block.y + block.offsetY + y;
		
		// Bounds check
		if(worldX < 0) return false;
		if(worldY < 0) continue;
		if(worldX >= bounds.width) return true;
		if(worldY >= bounds.height) continue;
		
		// Block check
		if(blockMap[worldX + (worldY * bounds.width)] != nullptr) return true;
	}
	return false;
}
