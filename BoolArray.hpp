#ifndef TETRUINO_BOOLARRAY_HPP
#define TETRUINO_BOOLARRAY_HPP

#include <Arduino.h>

namespace Tetruino
{
	class BoolArray
	{
	public:
		BoolArray(unsigned long size, const uint8_t state[] = nullptr);
		BoolArray(const BoolArray& other);
		~BoolArray();
		
		unsigned long getSize();
		
		bool get(unsigned long index) const;		// Read
		void set(unsigned long index, bool value);	// Write
		
		void clear();
		
		BoolArray& operator=(const BoolArray& other);
	protected:
		unsigned long size;
		
		uint8_t* arrayBytes;
		unsigned int arrayBytesCount;
	};
}

#endif