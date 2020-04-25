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
	
	namespace Blocks
	{
		// Starts at index 0, then right to left.
		static constexpr uint8_t IShapeRaw[] = { 0b11110000u, 0b0u };
		static constexpr unsigned char ISize = 16;
		static const BoolArray IShape(ISize, IShapeRaw);
		
		static constexpr uint8_t OShapeRaw[] = { 0b1111u };
		static constexpr unsigned char OSize = 4;
		static const BoolArray OShape(OSize, OShapeRaw);
		
		static constexpr uint8_t TShapeRaw[] = { 0b11010000u, 0b1u };
		static constexpr unsigned char TSize = 9;
		static const BoolArray TShape(TSize, TShapeRaw);
		
		static constexpr uint8_t SShapeRaw[] = { 0b11110000u, 0b0u };
		static constexpr unsigned char SSize = 9;
		static const BoolArray SShape(SSize, SShapeRaw);
		
		static constexpr uint8_t ZShapeRaw[] = { 0b10011000u, 0b1u };
		static constexpr unsigned char ZSize = 9;
		static const BoolArray ZShape(ZSize, ZShapeRaw);
		
		static constexpr uint8_t JShapeRaw[] = { 0b11001000u, 0b1u };
		static constexpr unsigned char JSize = 9;
		static const BoolArray JShape(JSize, JShapeRaw);
		
		static constexpr uint8_t LShapeRaw[] = { 0b11100000u, 0b1u };
		static constexpr unsigned char LSize = 9;
		static const BoolArray LShape(LSize, LShapeRaw);
	};
}

#endif
