#ifndef TETRUINO_RENDERER_HPP
#define TETRUINO_RENDERER_HPP

#include "Colour.hpp"
#include "Bounds.hpp"
#include "Block.hpp"

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
		Renderer(const Bounds& bounds);
		~Renderer();
		
		void addBlock(const Block& block, int x, int y);
		
		void draw();
		void clear();
	protected:
		const Bounds& bounds;
		Colour* buffer;
	private:
		void flipBuffer();
	};
}

#endif