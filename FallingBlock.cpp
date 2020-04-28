#include "FallingBlock.hpp"

using namespace Tetruino;

/* 
 * Like all collision code, this is an absolute mess.
 */
uint8_t FallingBlock::isColliding() const
{
	bool left = false;
	bool right = false;
	bool top = false;
	bool bottom = false;
	
	const Bounds bounds = getBounds();
	
	// Quick side checks
	if((short) bounds.minX - 1 < 0) left = true;
	if((short) bounds.maxX + 1 >= world->bounds.width) right = true;
	if((short) bounds.minY - 1 < 0) top = true;
	if((short) bounds.maxY + 1 >= world->bounds.height) bottom = true;
	
	/*
		In-depth collision map check
	 */
	for(unsigned char shapeY = bounds.minY; shapeY <= bounds.maxY; shapeY++)
	for(unsigned char shapeX = bounds.minX; shapeX <= bounds.maxX; shapeX++)
	{
		// Continue if shape is not at position
		if(!shape.get(shapeX + (shapeY * size))) continue;
		
		int worldX = x + offsetX + shapeX;
		int worldY = y + offsetY + shapeY;
		
		// Left
		if(shapeX == bounds.minX)
		{
			worldX--;
			
			if(worldX < 0) goto leftCheckEnd;
			if(world->getCollisionMap().get(worldX + (worldY * world->bounds.width)))
			{
				// Hit a block to the left
				left = true;
			}
			
		leftCheckEnd:
			worldX++;
		}
		
		// Right
		if(shapeX == bounds.maxX)
		{
			worldX++;
			
			if(worldX > world->bounds.width) goto rightCheckEnd;
			if(world->getCollisionMap().get(worldX + (worldY * world->bounds.width)))
			{
				// Hit a block to the right
				right = true;
			}
			
		rightCheckEnd:
			worldX--;
		}
		
		// Down
		if(shapeY == bounds.maxY)
		{
			worldY++;
			
			if(worldY > world->bounds.height) goto downCheckEnd;
			if(world->getCollisionMap().get(worldX + (worldY * world->bounds.width)))
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

int FallingBlock::getX() const { return x; }
int FallingBlock::getY() const { return y; }

bool FallingBlock::setPosition(const int x, const int y)
{
	this->x = x;
	this->y = y;
	
	return isColliding();
}
