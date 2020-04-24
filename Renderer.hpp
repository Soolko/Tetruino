#ifndef TETRUINO_RENDERER_HPP
#define TETRUINO_RENDERER_HPP

#include "Colour.hpp"
#include "World.hpp"

#ifndef LEDType
#define LEDType NEOPIXEL
#else
#error Two renderers are defined, this is not good and will die probably maybe.
#endif

namespace Tetruino
{
	class Renderer
	{
	public:
		Renderer(const World& world);
		~Renderer();
		
		void setup();
		void loop();
		
		// World reference
		const World& world;
	protected:
		Colour* buffer;
	};
}

#endif