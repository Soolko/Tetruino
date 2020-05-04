#ifndef TETRUINO_GAME_HPP
#define TETRUINO_GAME_HPP

#include "Renderer.hpp"
#include "World.hpp"

namespace Tetruino
{
	class Game final
	{
	public:
		Game::Game(const Bounds& bounds) : renderer(bounds), world(bounds) {}
		~Game();
		
		void setup();
		void loop();
		
		void onInput();
	private:
		// Core objects
		Renderer renderer;
		World world;
		
		// Game loop
		unsigned long timer = 0;
		unsigned long lastTime = 0;
		
		// Block randomization
		const Block* nextBlock;
		Block* currentBlock;
		
		void pickNextBlock();
		const Block* getBlock(unsigned char id);
		const Block* getRandomBlock();
		
		// Rendering
		void render();
		void renderWorldStatic();
		void renderCurrentBlock();
		void renderNextBlock();
	};
}

#endif