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
			const BoolArray& baseShape,
			const Colour& colour,
			Rotation baseRotation = Rotation::up
		);
		
		unsigned char size;
		BoolArray shape;
		Rotation rotation;
		Colour colour;
		
		void rotateLeft();
		void rotateRight();
	};
	
	namespace Blocks
	{
		// Starts at index 0, then right to left.
		static constexpr uint8_t IShapeRaw[] = { 0b11110000u, 0b0u };
		static constexpr unsigned char ISize = 4;
		static const BoolArray IShape(16, IShapeRaw);
		static const Colour IColour = Colour { 0, ColourBrightness, ColourBrightness };
		
		static constexpr uint8_t OShapeRaw[] = { 0b1111u };
		static constexpr unsigned char OSize = 2;
		static const BoolArray OShape(4, OShapeRaw);
		static const Colour OColour = Colour { ColourBrightness, ColourBrightness, 0 };
		
		static constexpr uint8_t TShapeRaw[] = { 0b11010000u, 0b1u };
		static constexpr unsigned char TSize = 3;
		static const BoolArray TShape(9, TShapeRaw);
		static const Colour TColour = Colour { ColourBrightness, 0, ColourBrightness };
		
		static constexpr uint8_t SShapeRaw[] = { 0b11110000u, 0b0u };
		static constexpr unsigned char SSize = 3;
		static const BoolArray SShape(9, SShapeRaw);
		static const Colour SColour = Colour { 0, ColourBrightness, 0 };
		
		static constexpr uint8_t ZShapeRaw[] = { 0b10011000u, 0b1u };
		static constexpr unsigned char ZSize = 3;
		static const BoolArray ZShape(9, ZShapeRaw);
		static const Colour ZColour = Colour { ColourBrightness, 0, 0 };
		
		static constexpr uint8_t JShapeRaw[] = { 0b11001000u, 0b1u };
		static constexpr unsigned char JSize = 3;
		static const BoolArray JShape(9, JShapeRaw);
		static const Colour JColour = Colour { 0, 0, ColourBrightness };
		
		static constexpr uint8_t LShapeRaw[] = { 0b11100000u, 0b1u };
		static constexpr unsigned char LSize = 3;
		static const BoolArray LShape(9, LShapeRaw);
		static const Colour LColour = Colour { ColourBrightness, ColourBrightness / 4, 0 };
	};
}

#endif