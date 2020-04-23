#include "Game.hpp"

using namespace Tetruino;

Game::Game(const unsigned width, const unsigned height)
{
	world = new World(width, height);
	renderer = new Renderer(*world);
}

Game::~Game()
{
	delete renderer;
	delete world;
}

void Game::setup()
{
	renderer->setup();
}

void Game::loop()
{
	renderer->loop();
}
