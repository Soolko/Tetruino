#ifndef TETRUINO_GAME_HPP
#define TETRUINO_GAME_HPP

#include "World.hpp"
#include "Renderer.hpp"

namespace Tetruino
{
	class Game
	{
	public:
		Game(const Bounds& bounds);
		~Game();
		
		void setup();
		void loop();
	};
}

#endif