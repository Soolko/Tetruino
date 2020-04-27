#include "World.hpp"

#include <Arduino.h>

using namespace Tetruino;

World::~World()
{
	delete blocks;
}

const BoolArray& World::getCollisionMap() const { return collisionMap; }
const Vector<Block>& World::getBlocks() const { return *blocks; }

void World::addBlock(const Block& block)
{
	if(blocks == nullptr) blocks = new Vector<Block>(block);
	else blocks->add(block);
}
