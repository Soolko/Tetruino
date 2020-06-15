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
	currentBlock->x = centreBlockX(*currentBlock);
	
	render();
	lastTime = micros();
}

void Game::loop()
{
	// Timer stuff
	timer += micros() - lastTime;
	lastTime = micros();
	
	// Update block every second
	if(timer >= 100000)
	{
		// Drop block
		if(world.hitBottom(*currentBlock))
		{
			// Hit bottom
			world.addBlock(*currentBlock);
			pickNextBlock();
		}
		else currentBlock->y++;
		
		// Reset timer
		timer = 0;
	}
	
	// Get Input
	input.update();
	
	/* Flip these if you have issues */
	if(input.left())	currentBlock->x++;
	if(input.right())	currentBlock->x--;
	if(input.rotate())	currentBlock->rotateRight();
	
	// Always render
	render();
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
	currentBlock->x = centreBlockX(*currentBlock);
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

int Game::centreBlockX(const Block& block) const { return (world.bounds.width / 2) - (block.getBounds().getWidth() / 2); }
