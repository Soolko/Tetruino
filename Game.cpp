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
	timer += micros() - lastTime;
	lastTime = micros();
	
	constexpr unsigned long forcedUpdatePeriod = 100000;
	
	if(timer >= forcedUpdatePeriod) // Force an update after 1 second
	{
		currentBlock->y++;
		render();
		
		timer -= forcedUpdatePeriod;
	}
	
	if(world.isColliding(*currentBlock) & (uint8_t) World::CollisionStatus::bottom)
	{
		// Hit something, next block
		world.addBlock(*currentBlock);
		pickNextBlock();
		timer = 0;
	}
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

const Block* Game::getBlock(const unsigned char index)
{
	switch(index)
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

const Block* Game::getRandomBlock() { return getBlock(random(Blocks::blockCount)); }
