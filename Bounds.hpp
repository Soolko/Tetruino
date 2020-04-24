#ifndef TETRUINO_BOUNDS_HPP
#define TETRUINO_BOUNDS_HPP

namespace Tetruino
{
	struct Bounds
	{
		unsigned int width, height;
		unsigned int getGridCount() const;
	};
}

#endif