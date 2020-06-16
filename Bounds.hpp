#ifndef TETRUINO_BOUNDS_HPP
#define TETRUINO_BOUNDS_HPP

namespace Tetruino
{
	struct Bounds
	{
		uint8_t width, height;
		unsigned short getGridCount() const;
	};
}

#endif