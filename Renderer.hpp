#ifndef TETRUINO_RENDERER_HPP
#define TETRUINO_RENDERER_HPP

#include "World.hpp"
#include <FastLED.h>

#ifndef LEDType
#define LEDType NEOPIXEL
#else
#error Two renderers are defined, this is not good and will fuck stuff up probably maybe.
#endif

namespace Tetruino
{
	typedef CRGB Colour;
	class Renderer
	{
	public:
		Renderer(const World& world);
		void setup();
		void loop();
	protected:
		const World& world;
		
		// Set pin here
		constexpr uint8_t pin = 3;
	};
}

#endif