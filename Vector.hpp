#ifndef TETRUINO_VECTOR_HPP
#define TETRUINO_VECTOR_HPP

namespace Tetruino
{
	template<typename T> class Vector final
	{
	public:
		Vector(T value) : value(value), next(nullptr) {}
		~Vector() { if(next != nullptr) delete next; }
		
		T value;
		Vector* next;
	};
}

#endif