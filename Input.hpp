#ifndef TETRUINO_INPUT_HPP
#define TETRUINO_INPUT_HPP

#include <Arduino.h>

namespace Tetruino
{
	class Input
	{
	public:
		// POD, always uint8_t for pins.
		union KeyMap
		{
			struct
			{
				uint8_t left;
				uint8_t right;
				
				uint8_t rotate;
			};
			
			uint8_t raw[3];
		};
		
		// Vars
		Input(const KeyMap& keymap);
		const KeyMap keymap;
		
		// Update
		void update();
		
		// Checks
		bool left();
		bool right();
		bool rotate();
	private:
		// Status
		bool leftDown = false;
		bool leftPressed = false;
		
		bool rightDown = false;
		bool rightPressed = false;
		
		bool rotateDown = false;
		bool rotatePressed = false;
	};
}

#endif