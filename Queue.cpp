#include <bits/stdc++.h>
using namespace std;

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
			/*
			for (int i = f; i < r; i = (i + 1) % cap)
			{
				cout << data[i] << " ";
				newData[ff] = data[i];
				ff++;
			}

			cout << endl;*/

			delete []data;
			data = newData;
			cap = cap * 2;
			f = 0;
			r = cap;

			// cout << "Queue is Full!!" << endl;
			// return;
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
int main ()
{
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen ("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen ("output.txt", "w", stdout);
#endif
	QueueUsingArray<int> q(5);
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
