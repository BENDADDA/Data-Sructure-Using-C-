#include<iostream>
using namespace std;
namespace ds {
	template<class T1>
	struct Node
	{
		T1 data;
		Node<T1> *next;
		Node(T1 data, Node<T1>*next)
		{
			this->data = data;
			this->next = next;
		}
		Node(T1 data)
		{
			this->data = data;
			this->next = nullptr;
		}
		Node()
		{
			this->next = nullptr;
		}
	};

}
