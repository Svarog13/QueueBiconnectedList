#include<iostream>
#include<queue>

template<typename T>
class Queue
{
private:
	class Node
	{
	public:
		Node* next;
		Node* prev;
		T value;

		Node(T value, Node* next = nullptr, Node* prev = nullptr) : value{ value }, next{ next }, prev{ prev } {}
	};

	Node* head;
	Node* tail;
	int size;
public:
	Queue() : size{ 0 }, head{ nullptr }, tail{ nullptr } {}

	int getSize() const
	{
		return size;
	}
	
	bool isEmpty() const
	{
		return size <= 0;
	}
	
	void push(T value)
	{
		if (head == nullptr)
		{
			head = new Node(value);
			tail = head;
			size++;
			return;
		}

		Node* tmp = new Node(value);
		tail->next = tmp;
		tmp->prev = tail;
		tail = tmp;
		size++;
	}

	void pop()
	{
		if (head != nullptr)
		{
			if(size == 1)
			{
				delete head;
				head = nullptr;
				tail = nullptr;
				size = 0;
			}

			head = head->next;
			delete head->prev;
			head->prev = nullptr;
			size--;

		}
	}
	T& front()
	{
		if (head != nullptr)
		{
			return head->value;
		}

		throw std::out_of_range("Queue is empty");
	}
	T& back()
	{
		if (tail != nullptr)
		{
			return tail->value;
		}
		throw std::out_of_range("Queue is empty");
	}
};

int main()
{
	Queue<int> queue;
	queue.push(10);
	queue.push(11);
	queue.push(12);
	queue.push(13);

	while (!queue.isEmpty())
	{
		std::cout << queue.front() << std::endl;
		queue.pop();
	}

	return 0;
}

//	1. Реалізувати шаблонний клас «Черга» на основі
//	двосторонній список.
