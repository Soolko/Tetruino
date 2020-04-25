#include <Arduino.h>

#include "World.hpp"
#include "Block.hpp"

using namespace Tetruino;

World::World(const Bounds& bounds, const Renderer& renderer) : bounds(bounds), renderer(&renderer)
{
	
}

const Block* World::getCurrentBlock() { return currentBlock; }
const Block* World::getNextBlock() { return nextBlock; }

const Block* World::randomBlock()
{
	long result = random(0, blockCount);
	return blockList[result];
}
