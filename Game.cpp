#include "Game.hpp"

using namespace Tetruino;

Game::Game(const Bounds& bounds) : bounds(bounds)
{
	renderer = new Renderer(this->bounds);
	world = new World(this->bounds, *renderer);
}

Game::~Game()
{
	delete world;
	delete renderer;
}

void Game::setup()
{
	
}

void Game::loop()
{
	
}
