#include <Arduino.h>
#include <FastLED.h>

#include "Game.hpp"

using namespace Tetruino;

// Constants
constexpr unsigned Width = 32, Height = 8;

// Objects
Game game(Width, Height);

// Arduino method pass-on
void setup() { game.setup(); }
void loop()  { game.loop(); }
