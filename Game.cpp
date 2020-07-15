#include "Game.hpp"

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
		if(world.hitBottom(*currentBlock))	// Hit bottom
		{
			// Add block
			world.addBlock(*currentBlock);
			
			// Clear
			clearLines();
			
			// Select next
			pickNextBlock();
		}
		else currentBlock->y++;
		
		// Reset timer
		timer = 0;
	}
	
	// Get Input
	input.update();
	
	/* Flip these if you want to. */
	if(input.left() && !world.hitLeft(*currentBlock))	currentBlock->x--;
	if(input.right() && !world.hitRight(*currentBlock))	currentBlock->x++;
	if(input.rotate())	currentBlock->rotateRight();
	
	// Always render
	render();
}

inline void Game::clearLines()
{
	// Get the line numbers
	Vector<uint8_t>* lines = world.checkLines();
	
	// Nothing to do, and lines isn't allocated.
	// Technically could memory leak here, but I don't see how from the world.checkLines method.
	if(lines == nullptr) return;
	
	// Iterate through each line
	auto* current = lines;
	while(current != nullptr)
	{
		// Display line
		for(uint8_t x = 0; x < world.bounds.width; x++)
		{
			renderer.drawPixel(x, current->value, Colour { ColourBrightness * 2, ColourBrightness * 2, ColourBrightness * 2 });
			renderer.draw();
			delay(50);
		}
		
		// Clear line
		world.clearLine(current->value);
		
		// Reset renderer
		render();
		
		// Next
		current = current->next;
	}
	delete lines;
}

void Game::render()
{
	renderer.clear();
	
	renderWorldStatic();
	renderCurrentBlock();
	renderNextBlock();
	
	renderer.draw();
}

inline void Game::renderWorldStatic()
{
	renderer.drawMap(world.blockMap, world.bounds);
}

inline void Game::renderCurrentBlock()
{
	renderer.drawBlock(*currentBlock, currentBlock->x, currentBlock->y);
}

inline void Game::renderNextBlock()
{
	constexpr uint8_t brightness = ColourBrightness / 4;
	const Block::ShapeBounds shapeBounds = nextBlock->getBounds();
	const uint8_t blockWidth = shapeBounds.maxX - shapeBounds.minX;
	
	renderer.drawBlock
	(
		*nextBlock,
		6 - blockWidth, 1,
		true, Colour { brightness, brightness, brightness },
		true
	);
}

inline void Game::pickNextBlock()
{
	// Replace next block
	delete currentBlock;
	currentBlock = new Block(*nextBlock);
	currentBlock->x = centreBlockX(*currentBlock);
	nextBlock = getRandomBlock();
}

inline const Block* Game::getRandomBlock()
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

inline int Game::centreBlockX(const Block& block) const
{
	return (world.bounds.width / 2) - (block.getBounds().getWidth() / 2);
}
