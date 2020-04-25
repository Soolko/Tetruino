#include <Arduino.h>

#include "World.hpp"
#include "Block.hpp"

using namespace Tetruino;

World::World(const Bounds& bounds, const Renderer& renderer) : bounds(bounds), renderer(&renderer)
{
	collisionMap = new BoolArray(bounds.getGridCount());
}

World::~World()
{
	delete collisionMap;
}
