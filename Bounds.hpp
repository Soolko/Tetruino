#ifndef TETRUINO_BOUNDS_HPP
#define TETRUINO_BOUNDS_HPP

namespace Tetruino
{
	struct Bounds
	{
		unsigned char width, height;
		unsigned short getGridCount() const;
	};
}

#endif