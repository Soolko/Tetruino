#ifndef TETRUINO_GAME_HPP
#define TETRUINO_GAME_HPP

#include "World.hpp"
#include "Renderer.hpp"

namespace Tetruino
{
	class Game
	{
	public:
		Game
		(
			// Render Settings
			const unsigned width, const unsigned height
		);
		~Game();
		
		void setup();
		void loop();
		
		World* world;
		Renderer* renderer;
	};
}

#endif