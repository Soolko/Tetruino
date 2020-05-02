#ifndef TETRUINO_VECTOR_HPP
#define TETRUINO_VECTOR_HPP

namespace Tetruino
{
	template<typename T> struct Vector final
	{
		Vector(const T value) : value(value) {}
		~Vector()
		{
			if(next != nullptr) delete next;
		}
		
		T value;
		
		void add(const T item)
		{
			next = new Vector<T>(item);
		}
		
		T& operator[](const unsigned short index)
		{
			Vector* current = this;
			unsigned short currentIndex = 0;
			
			while(currentIndex++ < index) current = next;
			
			return current->value;
		}
	private:
		Vector<T>* next;
	};
}

#endif