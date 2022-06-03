#pragma once
namespace ds {
	template<class T>
	class DynamicArray
	{
		//signture
	public:
		T Get(int value);
		void Set(T value);
		void Display();
		DynamicArray();
		~DynamicArray();

	private:
		T*Array;
		int size;
		int count;
		T* CopyOf(T*a, int size);
	};
	//Implmentation
	template<class T>
	DynamicArray<T>::DynamicArray()
	{
		Array = new T[1];
		size = 1;
		count = 0;
		
	}
	template<class T>
	T DynamicArray<T>::Get(int value)
	{
		return Array[value];
	}
	template<class T>
	T* DynamicArray<T>::CopyOf(T*a, int size)
	{
		T*table = new T[size];
		for (int i = 0; i<count; i++)
		{
			table[i] = a[i];
		}
		return table;
	}
	template<class T>
	void DynamicArray<T>::Set(T value)
	{
		if (count == size) { size = size * 2; Array = CopyOf(Array, size); }
		Array[count] = value;
		count++;
	}
	template<class T>
	void DynamicArray<T>::Display()
	{
		for (int i = 0; i<count; i++)
			cout << Array[i] << " ";
	}
	template<class T>
	DynamicArray<T>::~DynamicArray()
	{
		delete[]Array;
	}

}