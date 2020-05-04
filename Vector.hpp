#ifndef TETRUINO_VECTOR_HPP
#define TETRUINO_VECTOR_HPP

namespace Tetruino
{
	template<typename T> struct Vector final
	{
		T value;
		Vector<T>* next;
		
		Vector(const T value) : value(value), next(nullptr) {}
		~Vector()
		{
			if(next != nullptr) delete next;
		}
		
		void add(const T& item)
		{
			Vector<T>* current = this;
			while(current->next != nullptr) current = current->next;
			current->next = new Vector<T>(item);
		}
	};
}

#endif