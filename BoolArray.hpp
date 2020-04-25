#ifndef TETRUINO_BOOLARRAY_HPP
#define TETRUINO_BOOLARRAY_HPP

namespace Tetruino
{
	class BoolArray
	{
	public:
		BoolArray(unsigned long size);
		~BoolArray();
		
		const unsigned long size;
		
		bool get(unsigned long index) const;		// Read
		void set(unsigned long index, bool value);	// Write
	protected:
		unsigned char* arrayBytes;
		unsigned int arrayBytesCount;
	};
}

#endif