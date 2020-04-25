#include "BoolArray.hpp"

using namespace Tetruino;

BoolArray::BoolArray(const unsigned long size) : size(size)
{
	arrayBytesCount = size / 8u;
	if(size % 8 > 0) arrayBytesCount++;
	
	arrayBytes = new unsigned char[arrayBytesCount];
	for(unsigned int i = 0; i < arrayBytesCount; i++) arrayBytes[i] = 0;
}

BoolArray::~BoolArray()
{
	delete[] arrayBytes;
}

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
	
	unsigned char newInt = 0u;
	for(unsigned char i = 0; i < 8; i++)
	{
		newInt |= i == byteIndex ? (value << byteIndex) : (arrayBytes[arrayIndex] << i) & 1u;
	}
	arrayBytes[arrayIndex] = newInt;
}
