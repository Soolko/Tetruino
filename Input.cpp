#include "Input.hpp"

using namespace Tetruino;

Input::Input(const KeyMap& keymap) : keymap(keymap)
{
	// Initialise pins
	for(size_t i = 0; i < sizeof(KeyMap); i++) pinMode(keymap.raw[i], INPUT_PULLUP);
}


/*
	Key Updates
 */

void updateKey(const uint8_t key, bool* downVar, bool* pressedVar)
{
	*downVar = digitalRead(key) == LOW;
	if(!*downVar) *pressedVar = false;
}

void Input::update()
{
	updateKey(keymap.left, &leftDown, &leftPressed);
	updateKey(keymap.right, &rightDown, &rightPressed);
	updateKey(keymap.rotate, &rotateDown, &rotatePressed);
}


/*
	Key Checks
 */

bool checkKey(const bool downVar, bool* pressedVar)
{
	if(downVar && !*pressedVar)
	{
		*pressedVar = true;
		return true;
	}
	else return false;
}

bool Input::left()		{ return checkKey(leftDown, &leftPressed); }
bool Input::right()		{ return checkKey(rightDown, &rightPressed); }
bool Input::rotate()	{ return checkKey(rotateDown, &rotatePressed); }
