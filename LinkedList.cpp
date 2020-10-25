#include <bits/stdc++.h>
// #define int long long 
using namespace std;


//Created Node 
class Node
{
public:
	int data;
	Node* next;

	Node (int data)
	{
		this->data = data;
		this->next = NULL;
	}

};

//Make pair two maintain head and tail  in LL
class Pair
{
public:
	Node* h;
	Node* t;

	Pair ()
	{
		h=NULL;
		t=NULL;
	}
};

//Take Input in LL
Node* input ()
{
	int d;
	cin>>d;
	Node* head = NULL;
	Node* tail = NULL;

	while (d!=-1)
	{
		Node* newNode = new Node (d);

		if (head==NULL)
		{
			head=newNode;
			tail=newNode;
		}
		else
		{
			tail->next=newNode;
			tail=newNode;
		}

		cin>>d;
	}

	return head;
}


//Insert node in ith location of LL -- iterative
Node* insert (Node* head,int i,int d)
{
	Node* newNode = new Node(d);

	if (i==0)
	{
		newNode->next=head;
		head=newNode;
		return head;
	}

	int c=0;
	Node* temp = head;
	while (c<(i-1) && temp!=NULL)
	{
		temp=temp->next;
		c++;
	}

	if (temp!=NULL)
	{
		newNode->next=temp->next;
		temp->next=newNode;
	}

	return head;
}

//Insert node in ith location of LL -- recursion
Node* insertRec (Node* head,int i,int d)
{
	if (head==NULL)	
		return head;

	if (i==0)
	{
		Node* newNode = new Node(d);
		newNode->next=head;
		head=newNode;
		return head;
	}

	Node* x = insertRec (head->next,i-1,d);

	head->next=x;

	return head;
}

//Delete node in ith location of LL -- iterative
Node* delet (Node* head,int i)
{
	if (i==0)
	{
		Node* free=head;
		head=head->next;
		free->next=NULL;
		delete free;
		return head;
	}

	Node* temp=head;
	int c=0;
	while (temp!=NULL && c<i-1)
	{
		temp=temp->next;
		c++;
	}

	if (temp!=NULL)
	{
		Node* free=temp->next;
		temp->next=free->next;
		free->next=NULL;
		delete free;
	}

	return head;
}

//Delete node in ith location of LL -- recursion
Node* deletRec (Node* head,int i)
{
	if (head==NULL)
		return head;

	if (i==0)
	{
		Node* free=head;
		head=head->next;
		free=NULL;
		delete free;
		return head;
	}

	Node* x = deletRec(head->next,i-1);

	head->next=x;

	return head;
}


//Print LL
void print (Node* head)
{
	Node* temp=head;

	while (temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}

	cout<<endl;
}

//Find Mid element in LL
Node* mid (Node* head)
{
	Node* slow=head;
	Node* fast=head->next;

	while (fast!=NULL && (fast->next)!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}

	return slow;
}

//Merge 2 sorted LL
Node* merge(Node* h1,Node* h2)
{
	Node* fh=NULL;Node* ft=NULL;

	while (h1!=NULL && h2!=NULL)
	{
		if (fh==NULL)
		{
			if (h1->data<h2->data)
			{
				fh=h1;
				ft=h1;
				h1=h1->next;
			}
			else
			{
				fh=h2;
				ft=h2;
				h2=h2->next;
			}
		}
		else
		{
			if (h1->data<h2->data)
			{
				ft->next=h1;
				ft=h1;
				h1=h1->next;
			}
			else
			{
				ft->next=h2;
				ft=h2;
				h2=h2->next;
			}
		}

		// ft=ft->next;
	}

	while (h1!=NULL)
	{
		ft->next=h1;
		ft=h1;
		h1=h1->next;
	}

	while (h2!=NULL)
	{
		ft->next=h2;
		ft=h2;
		h2=h2->next;
	}

	return fh;
}

//Merge Sort 
Node* mergeSort (Node* h)
{
	if ((h->next)==NULL)
		return h;

	Node* midele = mid(h);

	Node* g = midele->next;
	midele->next = NULL;

	Node* h1 = mergeSort (h);
	Node* h2 = mergeSort (g);

	Node* head = merge (h1,h2);

	return head;
}

//Reverse LL using Recursion
Pair* Reverse (Node* head)
{
	if (head==NULL || head->next==NULL)
	{
		Pair* p = new Pair();
		p->h=head;
		p->t=head;
		return p;
	}

	Pair* p = Reverse (head->next);

	p->t->next=head;
	p->t=head;
	head->next=NULL;

	return p;

	// cout<<head->data<<" ";
}

//Reverse LL using Recursion
Node* Reverse1 (Node* head)
{
	if (head==NULL || head->next==NULL)
	{
		return head;
	}

	Node* x = Reverse1 (head->next);

	Node* tail = head->next;
	tail->next = head;
	head->next=NULL;

	return x;

	// cout<<head->data<<" ";
}

//Reverse LL iterative way
Node* ReverseIt (Node* head)
{
	Node *prev,*cur,*nex;
	prev = NULL;
	cur=head;
	nex=head->next;

	while (cur!=NULL)
	{
		cur->next=prev;
		prev=cur;
		cur=nex;
		if (nex==NULL)
			break;
		nex=nex->next;
	}

	return prev;
}

int main ()
{
    #ifndef ONLINE_JUDGE
        freopen ("intput1.txt","r",stdin);
        freopen ("output1.txt","w",stdout);
    #endif

    	Node* h1 = input ();
    	// Node* h2 = input ();
    	print (h1);
    	// print (h2);
    	// int i,d;
    	// cin>>i>>d;
    	// head = insertRec (head,i,d);
    	// print (head);
    	// cin>>i;
    	// head = deletRec (head,i);
    	// print (head);
    	// Node* midele = mid(head);
    	// cout<<midele->data<<endl;
    	// Node* head = mergeSort (h1);
    	// print(head);
    	// Pair* head = Reverse(h1);
    	Node* head = ReverseIt (h1);
    	print(head);
}
