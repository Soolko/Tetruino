#ifndef TETRUINO_GAME_HPP
#define TETRUINO_GAME_HPP

#include "World.hpp"
#include "Renderer.hpp"

namespace Tetruino
{
	class Game final
	{
	public:
		Game(const Bounds& bounds);
		~Game();
		
		void setup();
		void loop();
	private:
		// Const settings
		const Bounds bounds;
		
		// Core objects
		Renderer* renderer;
		World* world;
	};
}

#endif