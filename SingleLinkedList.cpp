#include <iostream>
#include <cstdlib>

template<typename T>
class List
{
public:
	List();
	~List();
	void push_back(T data);
	int GetSize() { return Size; };
	T& operator[](const int index);
	void pop_front();
	void clear();
	void push_front(T data);
	void pop_back();
	void insert_at(T value, int index);
	void remove_at(int index);
private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head;
};

template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	this->clear();
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::pop_front()
{
	if (head != nullptr)
	{
		Node<T>* temp = head->pNext;
		delete head;
		Size--;
		head = temp;
	}
}

template<typename T>
void List<T>::clear()
{
	while (this->Size)
	{
		this->pop_front();
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::pop_back()
{
	if (head != nullptr)
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		delete current;
		Size--;
	}
}

template<typename T>
void List<T>::insert_at(T data, int index)
{
	if (index > Size)
	{
		push_back(data);
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		previous->pNext = new Node<T>(data, previous->pNext);
		Size++;
	}
}

template<typename T>
void List<T>::remove_at(int index)
{
	if (index > Size)
	{
		pop_back();
	}
	else if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* adress_to_delete = previous->pNext;
		Node<T>* next_adress = adress_to_delete->pNext;
		delete previous->pNext;
		previous->pNext = next_adress;
		Size--;
	}
}

int main()
{
	List<int> lst;
	for (int i = 0; i < 5; i++)
	{
		lst.push_back(rand() % 100);
		std::cout << lst[i] << std::endl;
	}
	std::cout << "size = " << lst.GetSize() << std::endl;

	//lst.insert_at(444, 3);
	//lst.insert_at(666, 14);
	//lst.insert_at(777, 3);
	lst.remove_at(2);
	lst.remove_at(0);

	std::cout << "-----After manipulations-----" << std::endl;

	for (int i = 0; i < lst.GetSize(); i++)
	{
		std::cout << lst[i] << std::endl;
	}
	std::cout << "size = " << lst.GetSize() << std::endl;
	return 0;
}
