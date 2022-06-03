template<class T>
struct Root
{
	T data;
	Root<T>*right;
	Root<T>*left;
	Root(T data, Root<T>*left, Root<T>*right)
	{
		this->data = data;
		this->right = right;
		this->left = left;
	}
	Root(T data)
	{
		this->data = data;
		this->right = nullptr;
		this->left = nullptr;
	}
	Root()
	{
		this->right = nullptr;
		this->left = nullptr;
	}
};

namespace ds {
	
	//Signatures
	template<class T>
	class BinaryTree
	{
	public :
		void Add(T element);
		bool Search(T element);
		int GetCount();
		void Display();
		void Delete(T element);
		void Clear();
		BinaryTree();
		~BinaryTree();
	private:
		Root<T>*root=nullptr;
		int count=0;
		void Add(Root<T>*root, T element);
		void Display(Root<T>*root);
		bool Search(T element, Root<T>*node);
		void Clear(Root<T>*node);
		Root<T>*removerootn(Root<T>*node);

		
	};
	//Implementation
	template<class T>
	void BinaryTree<T>::Add(Root<T>*rootexplorer, T element)
	{
		if (rootexplorer == nullptr) { root = new Root<T>(element); return; }
		if (rootexplorer->data<element)
		{
			if(rootexplorer->right==nullptr)
			{
				rootexplorer->right = new Root<T>(element);
			}
			else
			{
				Add(rootexplorer->right, element);
			}
		}
		else 
		{
			if (rootexplorer->left == nullptr)
			{
				rootexplorer->left = new Root<T>(element);
			}
			else
			{
				Add(rootexplorer->left, element);
			}
		}
	}
	//Desplay
	template<class T>
	void BinaryTree<T>::Display(Root<T>*root)
	{
		if (root == nullptr) return;
		cout << root->data << " ";
		Display(root->left);
		Display(root->right);
	}
	template<class T>
	void BinaryTree<T>::Display()
	{
	
		Display(root);
		
	}
	//get the numeber of the nodes
	template<class T>
	int BinaryTree<T>::GetCount()
	{
		return count;
	}
	template<class T>
	void BinaryTree<T>::Add(T element)
	{
		Add(root, element);
		count++;
	}
	//Deconstructure
	template<class T>
	BinaryTree<T>::~BinaryTree()
	{
		Clear(root);
	}
	template<class T>
	BinaryTree<T>::BinaryTree()
	{
		this->root = nullptr;
		this->count = 0;
	}
	//Clear
	template<class T>	
	void BinaryTree<T>::Clear(Root<T>*node)
	{
		if (node == nullptr) return;
		Clear(node->left);
		Clear(node->right);
		delete node;
	}
	template<class T>
	void BinaryTree<T>::Clear()
	{
		Clear(root);
		root = nullptr;
		count = 0;
	}
	
	//search for element, with itration,O(n).
	template<class T>
	bool BinaryTree<T>::Search(T element)
	{
		Root<T>*temp = root;
		while (temp != nullptr)
		{
			if (temp->data == element) return true;
			if (temp->data < element)temp = temp->right;
			else temp = temp->left;
		}
		temp = nullptr;
		delete temp;
		return false;
	}
	//Remove
	template<class T>
	Root<T>*BinaryTree<T>::removerootn(Root<T>*node)
	{
		if (node->left == nullptr && node->right == nullptr)
		{
			node = nullptr;
		}
		else if (node->left != nullptr)
		{
			Root<T>*newroot = node->right;
			node->right = nullptr;
			node = node->left;
			Root<T>*temp = node;
			while (temp->right != nullptr)
			{
				temp = temp->right;
			}
			temp->right = newroot;
		}
		else node = node->right;
		return node;
	}
	template<class T>
	void BinaryTree<T>::Delete(T element)
	{
		
		
		if (root->data == element) { root = removerootn(root); count--; return; }
		Root<T>*temp = root;
		while (temp != nullptr)
		{
			
			if (temp->data<element)
			{
				if (temp->right != nullptr&& temp->right->data == element) 
				{ temp->right = removerootn(temp->right); count--; }
				else temp = temp->right;
			}
			else
			{
				if (temp->left != nullptr && temp->left->data == element)
				{ temp->left = removerootn(temp->left); count--; }
				else temp = temp->left;
			}
		}
		
		temp = nullptr;
		delete temp;
		
	}
}