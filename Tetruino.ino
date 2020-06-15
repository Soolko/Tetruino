#include <Arduino.h>
#include <FastLED.h>

#include "Game.hpp"
#include "Bounds.hpp"
#include "Input.hpp"

using namespace Tetruino;

// Bounds = X, Y of the matrix
// KeyMap = Left, Right, Rotate pins for the input
Game gameInstance(Bounds { 8, 32 }, Input::KeyMap { 4, 5, 6 });

void setup() { gameInstance.setup(); }
void loop()  { gameInstance.loop();  }
