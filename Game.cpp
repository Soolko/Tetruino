#include "Game.hpp"
#include "Block.hpp"

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
}

void Game::loop()
{
	renderCurrentBlock();
	renderNextBlock();
	renderer.draw();
	
	delay(1000);
	
	renderer.clear();
	
	pickNextBlock();
}

void Game::renderCurrentBlock()
{
	renderer.drawBlock(*currentBlock, 3, 3);
}

void Game::renderNextBlock()
{
	const Block::ShapeBounds shapeBounds = nextBlock->getBounds();
	const unsigned char blockWidth = shapeBounds.maxX - shapeBounds.minX;
	
	renderer.drawBlock
	(
		*nextBlock,
		6 - blockWidth, 1,
		true, Colour { ColourBrightness, ColourBrightness, ColourBrightness },
		true
	);
}

void Game::pickNextBlock()
{
	// Replace next block
	delete currentBlock;
	currentBlock = new Block(*nextBlock);
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
