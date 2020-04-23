#include "World.hpp"

using namespace Tetruino;

World::World(unsigned width, unsigned height) : width(width), height(height), ledCount(width * height)
{
	// Allocate world
	world = new Colour[ledCount];
	
	// Set background
	for(unsigned i = 0; i < ledCount; i++) world[i] = BackgroundColour;
}

World::~World()
{
	delete[] world;
}
