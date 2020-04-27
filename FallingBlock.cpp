#include "FallingBlock.hpp"

using namespace Tetruino;

bool FallingBlock::isColliding() const
{
	const unsigned int worldSize = world->bounds.getGridCount();
	
	for(unsigned char blockY = 0; blockY < size; blockY++)
	for(unsigned char blockX = 0; blockX < size; blockX++)
	{
		// If block doesn't exist at this position, move to next
		if(!shape.get(blockX + (blockY * size))) continue;
		
		// Block exists here, check world
		const int worldX = x + blockX;
		const int worldY = y + blockY;
		
		// World position invalid check
		if(worldX < 0 || worldY < 0) continue;
		
		// Get world index
		const unsigned long worldIndex = worldX + (worldY * world->bounds.width);
		
		// Check if hit end of world or another block
		if(worldIndex > worldSize) return true;
		if(world->getCollisionMap().get(worldIndex)) return true;
	}
	
	// Not hit anything
	return false;
}

int FallingBlock::getX() const { return x; }
int FallingBlock::getY() const { return y; }

bool FallingBlock::setPosition(const int x, const int y)
{
	this->x = x;
	this->y = y;
	
	return isColliding();
}
