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
	class Renderer
	{
	public:
		Renderer(const World& world);
		void setup();
		void loop();
	protected:
		const World& world;
	};
}

#endif