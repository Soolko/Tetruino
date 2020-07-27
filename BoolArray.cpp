#include "BoolArray.hpp"

using namespace Tetruino;

BoolArray::BoolArray(const unsigned long size, const uint8_t state[]) : size(size)
{
	// Calculate byte count
	arrayBytesCount = size / 8u;
	if(size % 8 > 0) arrayBytesCount++;
	
	// Allocate bytes
	arrayBytes = new uint8_t[arrayBytesCount];
	
	// If state is not supplied, clear, otherwise set the state.
	if(state == nullptr) clear();
	else for(unsigned int i = 0; i < arrayBytesCount; i++) arrayBytes[i] = state[i];
}

BoolArray::BoolArray(const BoolArray& other) : size(other.size), arrayBytesCount(other.arrayBytesCount)
{
	// Copy other bool array
	arrayBytes = new uint8_t[arrayBytesCount];
	for(unsigned int i = 0; i < arrayBytesCount; i++) arrayBytes[i] = other.arrayBytes[i];
}

// Set to new bool array
BoolArray& BoolArray::operator=(const BoolArray& other)
{
	arrayBytesCount = other.arrayBytesCount;
	
	// Reallocate bytes to other, hopefully doesn't cause fragmentation.
	delete[] arrayBytes;
	arrayBytes = new uint8_t[arrayBytesCount];
	
	// Copy & return reference
	for(unsigned int i = 0; i < arrayBytesCount; i++) arrayBytes[i] = other.arrayBytes[i];
	return *this;
}

BoolArray::~BoolArray()
{
	delete[] arrayBytes;
}


unsigned long BoolArray::getSize() { return size; }

bool BoolArray::get(const unsigned long index) const
{
	const unsigned int arrayIndex = index / 8u;
	const uint8_t byteIndex = index % 8u;
	
	return (arrayBytes[arrayIndex] >> byteIndex) & 1;
}

void BoolArray::set(const unsigned long index, const bool value)
{
	const unsigned int arrayIndex = index / 8u;
	const uint8_t byteIndex = index % 8u;
	
	arrayBytes[arrayIndex] = arrayBytes[arrayIndex] & (0xff - (1 << byteIndex));
	arrayBytes[arrayIndex] += (uint8_t) value << byteIndex;
}

void BoolArray::clear()
{
	for(unsigned int i = 0; i < arrayBytesCount; i++) arrayBytes[i] = 0;
}
