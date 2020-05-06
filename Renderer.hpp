#ifndef TETRUINO_RENDERER_HPP
#define TETRUINO_RENDERER_HPP

#include "Colour.hpp"
#include "Bounds.hpp"
#include "Block.hpp"

#define LEDType NEOPIXEL

namespace Tetruino
{
	class Renderer
	{
	public:
		Renderer(const Bounds& bounds);
		~Renderer();
		
		void drawPixel(int x, int y, Colour colour);
		void drawBlock
		(
			const Block& block,
			int x, int y,
			bool customColour = false, Colour colour = Colour { 0, 0, 0 },
			bool additive = false
		);
		void drawMap(const Colour** map, const Bounds& bounds);
		
		void draw();
		void clear();
	private:
		void flipBuffer();
	protected:
		const Bounds bounds;
		Colour* buffer;
	};
}

#endif