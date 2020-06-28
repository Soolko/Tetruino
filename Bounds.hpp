#ifndef TETRUINO_BOUNDS_HPP
#define TETRUINO_BOUNDS_HPP

namespace Tetruino
{
	struct Bounds
	{
		uint8_t width, height;
		inline uint16_t getGridCount() const { return width * height; };
	};
}

#endif