#ifndef TETRUINO_BLOCK_HPP
#define TETRUINO_BLOCK_HPP

#include "Rotation.hpp"
#include "Renderer.hpp"

namespace Tetruino
{
	class Block
	{
		Block
		(
			unsigned char bounds,
			bool baseShape[], Rotation baseRotation,
			const Colour& colour
		);
		
		const Colour& colour;
		const unsigned char bounds;
		
		constexpr const bool& getShape() const;
		constexpr Rotation getRotation() const;
		
		void rotateLeft();
		void rotateRight();
	private:
		Rotation rotation;
		bool shape[];
	};
}

#endif