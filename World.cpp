#include "World.hpp"
#include "Block.hpp"

using namespace Tetruino;

World::World(unsigned width, unsigned height) : width(width), height(height), ledCount(width * height)
{
	
}

const Block* World::getCurrentBlock() { return currentBlock; }
const Block* World::getNextBlock() { return nextBlock; }
