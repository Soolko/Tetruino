#include "Game.hpp"
#include "Block.hpp"

#include <Arduino.h>

using namespace Tetruino;

Game::~Game()
{
	if(currentBlock != nullptr)	delete currentBlock;
}

void Game::setup()
{
	// Random pin
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(A0, INPUT);
	randomSeed(analogRead(A0));
	
	// Create first blocks
	nextBlock = getRandomBlock();
	currentBlock = new Block(*getRandomBlock());
	currentBlock->x = world.bounds.width / 2 - currentBlock->getBounds().getWidth();
	
	render();
	lastTime = micros();
}

void Game::loop()
{
	render();
	
	// Drop block
	if(world.hitBottom(*currentBlock))
	{
		// Hit bottom
		world.addBlock(*currentBlock);
		pickNextBlock();
	}
	else currentBlock->y++;

	delay(500);
}

void Game::render()
{
	renderer.clear();
	
	renderWorldStatic();
	renderCurrentBlock();
	renderNextBlock();
	
	renderer.draw();
}

void Game::renderWorldStatic()
{
	renderer.drawMap(world.blockMap, world.bounds);
}

void Game::renderCurrentBlock()
{
	renderer.drawBlock(*currentBlock, currentBlock->x, currentBlock->y);
}

void Game::renderNextBlock()
{
	constexpr unsigned char brightness = ColourBrightness / 4;
	const Block::ShapeBounds shapeBounds = nextBlock->getBounds();
	const unsigned char blockWidth = shapeBounds.maxX - shapeBounds.minX;
	
	renderer.drawBlock
	(
		*nextBlock,
		6 - blockWidth, 1,
		true, Colour { brightness, brightness, brightness },
		true
	);
}

void Game::pickNextBlock()
{
	// Replace next block
	delete currentBlock;
	currentBlock = new Block(*nextBlock);
	currentBlock->x = world.bounds.width / 2 - currentBlock->getBounds().getWidth();
	nextBlock = getRandomBlock();
}

const Block* Game::getRandomBlock()
{
	switch(random(Blocks::blockCount))
	{
		default:
		case 0: return &Blocks::I;
		case 1: return &Blocks::O;
		case 2: return &Blocks::T;
		case 3: return &Blocks::S;
		case 4: return &Blocks::Z;
		case 5: return &Blocks::J;
		case 6: return &Blocks::L;
	}
}
