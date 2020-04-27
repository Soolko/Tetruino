#ifndef TETRUINO_BLOCK_HPP
#define TETRUINO_BLOCK_HPP

#include "BoolArray.hpp"
#include "Colour.hpp"
#include "Rotation.hpp"

namespace Tetruino
{
	class Block
	{
	public:
		Block(unsigned char size, const BoolArray& baseShape, const Colour colour, Rotation baseRotation = Rotation::up) : size(size), colour(colour), shape(baseShape), rotation(baseRotation) {}
		Block(const Block& other) : size(other.size), colour(other.colour), shape(other.shape), rotation(other.rotation) {}
		
		const unsigned char size;
		const Colour colour;
		BoolArray shape;
		Rotation rotation;
		
		void rotateLeft();
		void rotateRight();
	};
	
	namespace Blocks
	{
		static constexpr unsigned char blockCount = 7;
		
		extern const Block I;
		extern const Block O;
		extern const Block T;
		extern const Block S;
		extern const Block Z;
		extern const Block J;
		extern const Block L;
	};
}

#endif