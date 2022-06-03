#include"Node.h"
namespace ds
{
	//Signature
	template<class T>
	class Queue
	{
	public:
		int  Count;
		void Enqueue(T element);
		T Dequeue();
		T Peek();
		void Clear();
		void Display();
		bool IsEmpty();
		Queue();
		~Queue();
	private:
		Node<T>*front;
		Node<T>*Rear;
		int size;
		

	};
	
	//Implementation
	template<class T>
	Queue<T>::Queue()
	{
		this->size = 0;
		this->front = nullptr;
		this->Rear = nullptr;
	}
	template<class T>
	void Queue<T>::Enqueue(T element)
	{
		Node<T>*newRear = new Node<T>(element, nullptr);
		if (Rear == nullptr) { front = Rear = newRear;return;}
		Rear->next = newRear;
		Rear = Rear->next;
		size++;
	}
	template<class T>
	T Queue<T>::Dequeue()
	{
		Node<T>* temp = front;
		front = front->next;
		size--;
		temp=nullptr;
		return value;
	}
	template<class T>
	T Queue<T>::Peek()
	{
		T value = front->data;
		return value;
	}

	template<class T>
	void Queue<T>::Display()
	{
		Node<T>*temp = front;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	template<class T>
	void Queue<T>::Clear()
	{

		while (front != nullptr)
		{
			Node<T>*temp = front;
			front = front->next;
			delete temp;
		}
		size = 0;
	}
	//check if the stack is empty
	template<class T>
	bool Queue<T>::IsEmpty()
	{
		if (size == 0) return true;
		return false;
	}
	template<class T>
	Queue<T>::~Queue()
	{
		while (front != nullptr)
		{
			Node<T>*temp = front;
			front = front->next;
			delete temp;
		}
		
	}












}