#include <iostream>
#include "string"
#include <cstdlib>
using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();
	void push_back(T data);
	int GetSize() { return Size; }
	T& operator[](const int index);
	
private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data=T(), Node* pNext = nullptr)
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

int main()
{
	List<int> lst;
	int numbers_count;
	cout << "enter numbers count:";
	cin >> numbers_count;
	for (int i = 0; i < numbers_count; i++)
	{
		lst.push_back(rand()%100);
		cout << lst[i]  << endl;
	}

	return 0;
}