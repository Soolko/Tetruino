#include "Game.hpp"
#include "Block.hpp"

using namespace Tetruino;

Game::~Game()
{
	if(nextBlock != nullptr) delete nextBlock;
	if(currentBlock != nullptr) delete currentBlock;
}

void Game::setup()
{
	// Random pin
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(A0, INPUT);
	randomSeed(digitalRead(A0));
	
	// Create first blocks
	nextBlock = getRandomBlock();
	
	//pickNextBlock();
}

void Game::loop()
{
	constexpr unsigned char Brightness = ColourBrightness * 2;
	renderer.drawBlock(*nextBlock, 2, 2, true, Colour { Brightness, Brightness, Brightness });
	renderer.draw();
	
	delay(500);
	
	renderer.clear();
	pickNextBlock();
}

void Game::pickNextBlock()
{
	// Replace next block
	nextBlock = getRandomBlock();
}

const Block* Game::getBlock(unsigned char index)
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
