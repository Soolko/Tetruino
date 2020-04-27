#ifndef TETRUINO_VECTOR_HPP
#define TETRUINO_VECTOR_HPP

namespace Tetruino
{
	template<typename T> class VectorEntry final
	{
	public:
		VectorEntry(T initial) : data(initial) {}
		~VectorEntry()
		{
			// Should recurse as it calls the destructor for the next one in the vector.
			if(next != nullptr) delete next;
		}
		
		T data;
		VectorEntry<T>* next = nullptr;
		
		void add(T data)
		{
			next = new VectorEntry(data);
		}
	};
	
	template<typename T> class Vector final
	{
	public:
		Vector(T initial) : vector(initial) {}
		
		void add(T object)
		{
			getEndPointer()->add(object);
		}
		
		VectorEntry<T>* getEndPointer()
		{
			VectorEntry<T>* current = &vector;
			while(current->next != nullptr) current = current->next;
			return current;
		}
		
		const T& operator[](unsigned int index) const
		{
			VectorEntry<T>* current = &vector;
			for(unsigned int i = 0; i < index; i++) current = current->next;
			return *current;
		}
	private:
		VectorEntry<T> vector;
	};
}

#endif