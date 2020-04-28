#ifndef TETRUINO_GAME_HPP
#define TETRUINO_GAME_HPP

#include "World.hpp"
#include "Renderer.hpp"
#include "FallingBlock.hpp"

namespace Tetruino
{
	class Game final
	{
	public:
		Game::Game(const Bounds& bounds) : renderer(bounds), world(bounds) {}
		~Game();
		
		void setup();
		void loop();
	private:
		// Core objects
		Renderer renderer;
		World world;
		
		// Variables
		/*const*/ Block* nextBlock;
		FallingBlock* currentBlock;
		
		// Methods
		void pickNextBlock();
		/*const*/ Block* getBlock(unsigned char id);
		/*const*/ Block* getRandomBlock();
	};
}

#endif