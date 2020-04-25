#include "Game.hpp"
#include "Block.hpp"

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

Block* block;

void Game::setup()
{
	block = new Block(Blocks::ISize, Blocks::IShape, Blocks::IColour);
}

void Game::loop()
{
	renderer->clear();
	renderer->drawBlock(*block, 2, 2);
	renderer->draw();
	block->rotateRight();
}
