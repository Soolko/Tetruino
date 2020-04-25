#include "BoolArray.hpp"

using namespace Tetruino;

BoolArray::BoolArray(const unsigned long size, const uint8_t state[]) : size(size)
{
	arrayBytesCount = size / 8u;
	if(size % 8 > 0) arrayBytesCount++;
	
	arrayBytes = new uint8_t[arrayBytesCount];
	
	if(state == nullptr) clear();
	else
	{
		for(unsigned int i = 0; i < arrayBytesCount; i++) arrayBytes[i] = state[i];
	}
}

BoolArray::~BoolArray()
{
	delete[] arrayBytes;
}


unsigned long BoolArray::getSize() { return size; }


bool BoolArray::get(const unsigned long index) const
{
	const unsigned int arrayIndex = index / 8u;
	const unsigned char byteIndex = index % 8u;
	
	return (arrayBytes[arrayIndex] >> byteIndex) & 1;
}

void BoolArray::set(const unsigned long index, const bool value)
{
	const unsigned int arrayIndex = index / 8u;
	const unsigned char byteIndex = index % 8u;
	
	uint8_t newInt = 0u;
	for(unsigned char i = 0; i < 8; i++)
	{
		newInt |= i == byteIndex ? (value << byteIndex) : (arrayBytes[arrayIndex] << i) & 1u;
	}
	arrayBytes[arrayIndex] = newInt;
}


void BoolArray::clear()
{
	for(unsigned int i = 0; i < arrayBytesCount; i++) arrayBytes[i] = 0;
}
