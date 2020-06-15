#include "Input.hpp"

using namespace Tetruino;

Input::Input(const KeyMap& keymap) : keymap(keymap)
{
	for(size_t i = 0; i < sizeof(KeyMap); i++) pinMode(keymap.raw[i], INPUT_PULLUP);
}

#define Input_UpdateBuilder(key, downVar, pressedVar) downVar = digitalRead(key); if(!downVar) pressedVar = false
void Input::update()
{
	Input_UpdateBuilder(keymap.left, leftDown, leftPressed);		// Left
	Input_UpdateBuilder(keymap.right, rightDown, rightPressed);		// Right
	Input_UpdateBuilder(keymap.rotate, rotateDown, rotatePressed);	// Rotate
}

#define Input_CheckBuilder(downVar, pressedVar) if(downVar && !pressedVar) { pressedVar = true; return true; } else return false
bool Input::left()		{ Input_CheckBuilder(leftDown, leftPressed); }
bool Input::right()		{ Input_CheckBuilder(rightDown, rightPressed); }
bool Input::rotate()	{ Input_CheckBuilder(rotateDown, rotatePressed); }
