#ifndef TETRUINO_GAME_HPP
#define TETRUINO_GAME_HPP

#include "Renderer.hpp"
#include "World.hpp"
#include "Input.hpp"

namespace Tetruino
{
	class Game final
	{
	public:
		Game(const Bounds& bounds, const Input::KeyMap& keymap) : renderer(bounds), world(bounds), input(keymap) {}
		~Game();
		
		void setup();
		void loop();
		
		void onInput();
	private:
		// Core objects
		Renderer renderer;
		World world;
		Input input;
		
		// Game loop
		unsigned long timer = 0;
		unsigned long lastTime = 0;
		
		// Block randomization
		const Block* nextBlock;
		Block* currentBlock;
		
		void pickNextBlock();
		const Block* getRandomBlock();
		
		// Rendering
		void render();
		void renderWorldStatic();
		void renderCurrentBlock();
		void renderNextBlock();
		
		// Update
		void dropBlock();
		
		// Tools
		int centreBlockX(const Block& block) const;
	};
}

#endif