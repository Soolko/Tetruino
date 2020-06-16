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
			const unsigned char collisionX = (blockPosX + blockX);
			const unsigned char collisionY = (blockPosY + blockY);
			if(collisionX > bounds.width) continue;
			if(collisionY > bounds.height) continue;
			
			blockMap[collisionX + (collisionY * bounds.width)] = block.colour;
		}
	}
}

size_t World::checkLines(uint8_t* lines)
{
	// Store the lines
	Vector<uint8_t>* vector = nullptr;
	size_t size = 0;
	
	for(short y = bounds.height - 1; y >= 0; y--)
	{
		uint8_t hitCount = 0;
		for(uint8_t x = 0; x < bounds.width; x++)
		{
			if(blockMap[x + (y * bounds.width)] == nullptr) break;
			else hitCount++;
		}
		
		// Nothing hit, therefore there can't be anything above here,
		// so we can exit out of the loop.
		if(hitCount == 0) break;
		
		// This line is full.
		if(hitCount == bounds.width)
		{
			size += 1;
			if(vector == nullptr)
			{
				// If vector not initialised, initialise it.
				vector = new Vector<uint8_t>(y);
			}
			else
			{
				// Go to end of vector
				auto* current = vector;
				while(current->next != nullptr) current = vector->next;
				
				// Add to vector
				current->next = new Vector<uint8_t>(y);
			}
		}
	}
	
	// Nothing to do here
	if(size == 0) return 0;
	
	// Convert to array
	lines = new uint8_t[size];
	
	uint8_t i = 0;
	Vector<uint8_t>* current = vector;
	while(current->next != nullptr)
	{
		lines[i++] = current->value;
		current = current->next;
	}
	
	// Free up
	delete vector;
	
	// Return
	return size;
}

bool World::hitBottom(const Block& block)
{
	for(int16_t y = block.size - 1; y >= 0; y--)
	for(uint8_t x = 0; x <= block.size; x++)
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
