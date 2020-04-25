#ifndef TETRUINO_BLOCK_HPP
#define TETRUINO_BLOCK_HPP

#include "Rotation.hpp"
#include "Colour.hpp"

namespace Tetruino
{
	class Block
	{
	public:
		Block
		(
			unsigned char bounds,
			const bool* baseShape, Rotation baseRotation,
			const Colour& colour
		);
		~Block();
		
		const Colour colour;
		
		// The width or height of the shape. Width == Height.
		const unsigned char bounds;
		
		bool* shape;
		Rotation rotation;
		
		void rotateLeft();
		void rotateRight();
	private:
		void copyArray(const bool* source, bool* target);
	};
	
	namespace Blocks
	{
		constexpr bool straightShape[] = 
		{
			false,	false,	false,	false,
			true,	true,	true,	true,
			false,	false,	false,	false,
			false,	false,	false,	false
		};
		
		static const Block straight = Block
		(
			4,
			straightShape,
			Rotation::up,
			Colour { 0, ColourBrightness, ColourBrightness }
		);
		
		
		constexpr bool leftLShape[] =
		{
			false,	false,	false,
			true,	false,	false,
			true,	true,	true
		};
		
		static const Block leftL = Block
		(
			3,
			leftLShape,
			Rotation::up,
			Colour { 0, 0, ColourBrightness }
		);
		
		
		constexpr bool rightLShape[] =
		{
			false,	false,	false,
			false,	false,	true,
			true,	true,	true
		};
		
		static const Block rightL = Block
		(
			3,
			rightLShape,
			Rotation::up,
			Colour { ColourBrightness, ColourBrightness / 4, 0 }
		);
		
		
		constexpr bool squareShape[] =
		{
			true,	true,
			true,	true
		};
		
		static const Block square = Block
		(
			2,
			squareShape,
			Rotation::up,
			Colour { ColourBrightness, ColourBrightness, 0 }
		);
		
		
		constexpr bool leftZShape[] =
		{
			false,	false,	false,
			false,	true,	true,
			true,	true,	false
		};
		
		static const Block leftZ = Block
		(
			3,
			leftZShape,
			Rotation::up,
			Colour { 0, ColourBrightness, 0 }
		);
		
		
		constexpr bool rightZShape[] =
		{
			false,	false,	false,
			true,	true,	false,
			false,	true,	true
		};
		
		static const Block rightZ = Block
		(
			3,
			rightZShape,
			Rotation::up,
			Colour { ColourBrightness, 0, 0 }
		);
		
		
		constexpr bool TShape[] =
		{
			false,	false,	false,
			false,	true,	false,
			true,	true,	true
		};
		
		static const Block T = Block
		(
			3,
			TShape,
			Rotation::up,
			Colour { ColourBrightness, 0, ColourBrightness }
		);
	}
	
	constexpr unsigned char blockCount = 7;
	static const Block* blockList[blockCount] =
	{
		&Blocks::straight,
		
		&Blocks::leftL,
		&Blocks::rightL,
		
		&Blocks::square,
		
		&Blocks::leftZ,
		&Blocks::rightZ,
		
		&Blocks::T
	};
}

#endif
