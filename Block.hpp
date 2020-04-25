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
		Block
		(
			unsigned char size,
			const BoolArray baseShape, Rotation baseRotation,
			const Colour& colour
		);
		
		const unsigned char size;
		const Colour colour;
		
		BoolArray shape;
		Rotation rotation;
		
		void rotateLeft();
		void rotateRight();
	};
	
	class Blocks final
	{
	public:
		// Initialise
		Blocks() :
			_I(makeI()), _O(makeO()), _T(makeT()),
			_S(makeS()), _Z(makeZ()),
			_J(makeJ()), _L(makeL()) {}
		
		// Definitions
		static constexpr unsigned char blockCount = 7;
		const Block _I, _O, _T, _S, _Z, _J, _L;
		const Block* blocks[blockCount] = { &_I, &_O, &_T, &_S, &_Z, &_J, &_L };
	private:
		// Builder methods
		static const Block& makeI();
		static const Block& makeO();
		static const Block& makeT();
		static const Block& makeS();
		static const Block& makeZ();
		static const Block& makeJ();
		static const Block& makeL();
	};
	
	static const Blocks BlocksInstance = Blocks();
}

#endif
