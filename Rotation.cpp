#include "Rotation.hpp"

using namespace Tetruino;

Rotation Rotation::rotateLeft() const
{
	switch(value)
	{
		case Rotation::up:		return left;
		case Rotation::left:	return down;
		case Rotation::down:	return right;
		case Rotation::right:	return up;
	}
}

Rotation Rotation::rotateRight() const
{
	switch(value)
	{
		case Rotation::up:		return right;
		case Rotation::right:	return down;
		case Rotation::down:	return left;
		case Rotation::left:	return up;
	}
}
