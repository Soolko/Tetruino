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
	randomSeed(digitalRead(A0));
	
	// Create first blocks
	nextBlock = getRandomBlock();
	
	pickNextBlock();
}

void Game::loop()
{
	renderNextBlock();
	renderer.draw();
	
	delay(1000);
	
	renderer.clear();
	
	pickNextBlock();
}

void Game::renderNextBlock()
{
	const Block::Bounds bounds = nextBlock->getBounds();
	const unsigned char blockWidth = bounds.maxX - bounds.minX;
	
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
