#include"Node.h"
namespace ds
{	
	//Signature
	template<class T>
	class Stack 
	{
	public:
		void Push(T element);
		T Pop();
		T Peek();
		void Clear();
		void Display();
		bool IsEmpty();
		Stack();
		~Stack();
	private:
		Node<T>*top;
		int size;
	
	};

	//Implementation
	template<class T>
	Stack<T>::Stack()
	{
		this->size = 0;
		this->top = nullptr;
	}
	template<class T>
	void Stack<T>::Push(T element)
	{
		Node<T>*newtop = new Node<T>(element, top);
		top = newtop;
		size++;
	}
	template<class T>
	T Stack<T>::Pop()
	{
		T value = top->data;
		top = top->next;
		size--;
		return value;
	}

	template<class T>
	T Stack<T>::Peek()
	{	
		T value = top->data;
		return value;
	}
	template<class T>
	void Stack<T>::Display()
	{
		Node<T>*temp = top;
		while(temp!=nullptr)
		{
			cout << temp->data << " ";
			temp =temp->next;
		}
	}
	template<class T>
	void Stack<T>::Clear()
	{
		
		while (top != nullptr)
		{
			Node<T>*temp = top;
			top =top->next;
			delete temp;
		}
		size = 0;
	}
	//check if the stack is empty
	template<class T>
	bool Stack<T>::IsEmpty()
	{
		if (size == 0) return true;
		return false;
	}
	template<class T>
	Stack<T>::~Stack()
	{
		while (top != nullptr)
		{
			Node<T>*temp = top;
			top = top->next;
			delete temp;
		}
		
	}












}