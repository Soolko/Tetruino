#ifndef TETRUINO_MAIN_HPP
#define TETRUINO_MAIN_HPP

#include "FastLED/FastLED.h"
#include "World.hpp"

namespace Tetruino
{
	// Arduino
	void setup();
	void loop();
	
	// Objects
	World* getWorld();
}

#endif