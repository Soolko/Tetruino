#ifndef TETRUINO_GAME_HPP
#define TETRUINO_GAME_HPP

#include "Renderer.hpp"
#include "World.hpp"
#include "Input.hpp"
#include "Block.hpp"

#include <Arduino.h>

namespace Tetruino
{
	class Game final
	{
	public:
		Game(const Bounds& bounds, const Input::KeyMap& keymap) : renderer(bounds), world(bounds), input(keymap) {}
		~Game();
		
		void setup();
		void loop();
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
		
		inline void pickNextBlock();
		inline const Block* getRandomBlock();
		
		inline void clearLines();
		
		// Rendering
		void render();
		inline void renderWorldStatic();
		inline void renderCurrentBlock();
		inline void renderNextBlock();
		
		// Tools
		inline int centreBlockX(const Block& block) const;
	};
}

#endif