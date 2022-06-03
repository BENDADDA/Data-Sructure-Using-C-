#pragma once
#include"Node.h"
namespace ds
{

	
	//Signatures
	template<class T>
	class LinkedList
	{

	public:
		void Add(T data);
		void AddTail(T data);
		void Display();
		void ToList(T Array[], int l);
		T Delete();
		bool IsEmpty();
		int Find(T element);
		int GetSize();
		LinkedList();
		~LinkedList();


	private:
		Node<T>*head;
		Node<T>*last;
		int size;

	};

	//------------------------
	//Implementation
	//Constructor
	template<class T>
	LinkedList<T>::LinkedList()
	{
		this->size = 0;
		this->head = nullptr;
		this->last = nullptr;

	}
	/*Insert(k): adds k to the start of the list
	Insert an element at the start of the list. Just create a new element and move references. So that this
	new element becomes the new element of the list. This operation will take O(1) constant time.*/
	template<class T>
	void LinkedList<T>::Add(T data)
	{
		Node<T> *newnode = new Node<T>(data, head);
		head = newnode;
		if (size == 0) last = head;
		size++;
		
	}
	//Insert(k): adds k to the end of the list,The Complexty time is O(1).
	template<class T>
	void LinkedList<T>::AddTail(T data)
	{
		if (last == nullptr) last =head= Node<T>(data);
		last->next = new Node<T>(data, nullptr);
		last = last->next;
		size++;
	}
	//Delete(): delete element at the start of the list
	template<class T>
	T LinkedList<T>::Delete()
	{
		if (size == 0) return NULL;
		T value = head->data;
		head = head->next;
		size--;
		return value;

	}
	/*Find(k): find the position of element with value k
	Start with the first element and follow the reference until we get the value we are looking for or reach
	the end of the list. This operation will take O(N) time.
	Note: binary search does not work on linked lists.*/
	template<class T>
	int LinkedList<T>::Find(T element)
	{
		int i = 0;
		Node<T>temp = head;
		while (temp != nullptr)
		{
			if (temp->next == element)return i;
			temp = temp->next;
			i++;
		}
		return -1;
	}
	template <class T>
	void LinkedList<T>::Display()
	{
		Node<T>*temp = head;
		while (temp != nullptr)
		{
			cout << "-> " << temp->data;
			temp = temp->next;
		}

	}
	/*IsEmpty(): check if the number of elements in the list are zero.
	Just check the head reference of the list it should be Null. Which means list is empty. This operation
	will take O(1) time.*/
	template<class T>
	bool LinkedList<T>::IsEmpty()
	{
		if (size == 0)return true;
		return false;
	}
	template<class T>
	int LinkedList<T>::GetSize()
	{
		return size;
	}
	//Insert the element of the array in list.
	template<class T>
	void LinkedList<T>::ToList(T Array[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			Add(Array[i]);
		}
	}
	//Deconstructor
	template<class T>
	LinkedList<T>::~LinkedList()
	{
		while (head != nullptr)
		{
			Node <T>*temp = head;
			head = head->next;
			delete temp;
		}
	}

}
