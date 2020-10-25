/*Stack using Dynamic Array
  All operation is done in 
  O(1) time.
*/
#include <bits/stdc++.h>
using namespace std;
/*template <typename T>
class Stack
{
	T* data;
	int ind;
	int cap;
public:
	//Default Constructor
	Stack()
	{
		data = new T[5];
		ind=0;
		cap=5;
	}
	~Stack()
	{
		delete []data;
	}

	//Insert Function
	void push (T d)
	{
		if (ind==cap)
		{
			T* newdata = new T[cap];
			for (int i=0;i<cap;i++)
				newdata[i]=data[i];

			delete []data;
			data=newdata;
			cap=2*cap;
		}

		data[ind]=d;
		ind++;
	}

	//Delete Function
	T pop ()
	{
		if (ind==0)
		{
			cout<<"Stack is empty."<<endl;
			return 0;
		}

		ind--;
		return data[ind];
	}

	//Size of Stack
	int size ()
	{
		return ind;
	}

	//Check that stack is empty or not 
	bool isEmpty ()
	{
		return ind==0;
	}

	T top ()
	{
		if (ind==0)
		{
			cout<<"Stack is Empty."<<endl;
			return 0;
		}

		return data[ind-1];
	}

	void print ()
	{
		if (ind==0)
		{
			cout<<"Stack is Empty."<<endl;
			return;
		}

		for (int i=ind-1;i>=0;i--)
		{
			cout<<data[i]<<" ";
		}

		cout<<endl;
	}

	
};*/

/*Stack using Linked List 
  All operation will be done 
  in O(1) time.
*/
template <typename T>
class Node
{
public:
	T data;
	Node<T>* next;

	Node(T d)
	{
		data = d;
		next = NULL;
	}
};
template <typename T>
class Stack
{
	Node<T> *head;
	int s;
public:

	Stack()
	{
		head=NULL;
		s=0;
	}

	void push (T d)
	{
		Node<T>* newdata = new Node<T> (d);

		if (head==NULL)
		{
			head=newdata;
		}
		else
		{
			newdata->next=head;
			head=newdata;
		}
		s++;
	}

	T pop ()
	{
		if (head==NULL)
		{
			cout<<"Stack is Empty."<<endl;
			return 0;
		}
		Node<T>* free = head;
		head = head->next;
		T d = free->data;
		delete free;
		s--;
		return d;
	}

	bool isEmpty ()
	{
		return head==NULL?true:false;
	}

	int size ()
	{
		return s;
	}

	T top ()
	{
		if (head==NULL)
		{
			cout<<"Stack is Empty."<<endl;
			return 0;
		}

		return (head->data);
	}

	void print ()
	{
		if (head==NULL)
		{
			cout<<"Stack is Empty."<<endl;
			return;
		}

		Node<T>* temp=head;

		while (temp)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}

		cout<<endl;

	}


};

int main()
{
	#ifndef ONLINE_JUDGE
        freopen ("intput1.txt","r",stdin);
        freopen ("output1.txt","w",stdout);
    #endif

        Stack<int> s;
        s.push(1);
        s.push(2);
        s.push(3);
        s.print();
        int t = s.pop();
        cout<<"Element is deleted : "<<t<<endl;
        s.print();
        s.push(5);
        s.print();
        t = s.top();
        cout<<"Top element is : "<<t<<endl;
        s.print ();
        cout << s.size() << endl;
        cout << s.isEmpty () << endl;
	 
	return 0;
}
