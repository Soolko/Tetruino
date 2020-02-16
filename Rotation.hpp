#ifndef TETRUINO_ROTATION_HPP
#define TETRUINO_ROTATION_HPP

namespace Tetruino
{
	class Rotation
	{
	public:
		enum Value : char
		{
			up = 0,
			left = -1,
			down = -2,
			right = 1
		};
		
		// Allow copying other value
		Rotation() = default;
		constexpr Rotation(Value other) : value(other) {}
		
		// Allow in switch case
		operator Value() const { return value; }
		explicit operator bool() = delete;
		
		// Rotation functions
		Rotation rotateLeft() const;
		Rotation rotateRight() const;
	private:
		Value value;
	};
}

#endif