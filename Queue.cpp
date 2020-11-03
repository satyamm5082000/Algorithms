#include <bits/stdc++.h>
using namespace std;

/*
Implemented Queue
using Array and all
it function take O(1)
*/

template <typename T>
class QueueUsingArray {
	T* data;
	int r;
	int f;
	int s;
	int cap;

public:
	QueueUsingArray (int ss) {
		data = new T [ss];
		cap = ss;
		f = -1;
		r = 0;
		s = 0;
	}

	int size () {
		return s;
	}

	bool isEmpty () {
		return s == 0;
	}

	void enqueue (T d) {
		if (s == cap) {

			T* newData = new T [cap * 2];

			int ff = 0;

			for (int i = f; i < cap; i++)
			{
				newData[ff] = data[i];
				ff++;
			}

			for (int i = 0; i < f; i++)
			{
				newData[ff] = data[i];
				ff++;
			}

			delete []data;
			data = newData;
			cap = cap * 2;
			f = 0;
			r = cap;
		}

		data[r] = d;
		r = (r + 1) % cap;
		if (f == -1)
			f = 0;

		s++;
	}


	T front () {
		if (s == 0) {
			cout << "Queue is Empty!!" << endl;
			return 0;
		}
		return data[f];
	}

	T dequeue () {
		if (s == 0) {
			cout << "Queue is Empty!!" << endl;
			return 0;
		}
		T t = data[f];
		f = (f + 1) % cap;
		s--;
		if (s == 0) {
			f = -1;
			r = 0;
		}
		return t;

		s--;
	}
};

/*
Implemented Queue
using LinkList and all
it function take O(1)
*/
template <typename T>
class Node {

public:
	T data;
	Node<T> *next;

	Node(int d)
	{
		data = d;
		next = NULL;
	}
};

template <typename T>
class QueueUsingLL {

	Node<T> *head, *tail;
	int s = 0;

public:

	QueueUsingLL() {
		head = NULL;
		tail = NULL;
		s = 0;
	}

	int size () {
		return s;
	}

	bool isEmpty () {
		return s == 0;
	}

	void enqueue (T d) {
		Node<T>* newNode = new Node<T>(d);

		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}

		s++;
	}

	T front () {
		if (s == 0) {
			cout << "Queue is Empty!!" << endl;
			return 0;
		}
		return head->data;
	}

	T dequeue () {
		if (s == 0) {
			cout << "Queue is Empty!!" << endl;
			return 0;
		}

		Node<T>* free = head;
		head = NULL;
		delete head;
		head = free->next;

		return free->data;
		s--;
	}

};
int main ()
{
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen ("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen ("output.txt", "w", stdout);
#endif
	QueueUsingLL<int> q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);

	cout << q.front() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;

	cout << q.size() << endl;
	cout << q.isEmpty() << endl;
}
