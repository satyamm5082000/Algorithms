/*
It is all about
binary tree
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
	T data;
	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;

	BinaryTreeNode(T d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}

	//to delete tree by typing "delete root" only
	~BinaryTreeNode ()
	{
		delete left;
		delete right;
	}
};

//Take binary tree input DFS wise
BinaryTreeNode<int>* input() {
	int rootData;
	cin >> rootData;

	if (rootData == -1)
		return NULL;
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int>* leftChild = input();
	BinaryTreeNode<int>* rightChild = input();

	root->left = leftChild;
	root->right = rightChild;

	return root;
}

//Take binary ree input BFS wise
BinaryTreeNode<int>* input1() {
	int rootData;
	cin >> rootData;

	if (rootData == -1)
		return NULL;

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

	queue<BinaryTreeNode<int>*> q;
	q.push(root);

	while (!q.empty ())
	{
		BinaryTreeNode<int>* node = q.front ();
		q.pop();
		int l, r;
		cin >> l >> r;
		BinaryTreeNode<int> *leftChild = NULL, *rightChild = NULL;
		if (l != -1) {
			leftChild = new BinaryTreeNode<int>(l);
			q.push(leftChild);
		}
		if (r != -1) {
			rightChild = new BinaryTreeNode<int>(r);
			q.push(rightChild);
		}

		node->left = leftChild;
		node->right = rightChild;
	}

	return root;
}

//Print binary tree level wise
void print1(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		cout << "Tree is empty!!" << endl;
		return;
	}

	queue<BinaryTreeNode<int>*> q;
	q.push(root);

	while (!q.empty())
	{
		BinaryTreeNode<int>* node = q.front();
		q.pop();

		cout << node->data << ":";
		if (node->left) {
			cout << "L" << node->left->data << " ";
			q.push(node->left);
		}
		if (node->right) {
			cout << "R" << node->right->data;
			q.push(node->right);
		}

		cout << endl;
	}
}

//Print binary tree pre-order wise
void print(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		// cout << "Tree is Empty!!" << endl;
		return;
	}

	cout << root->data << ":";
	if (root->left)
		cout << "L" << root->left->data << " ";
	if (root->right)
		cout << "R" << root->right->data;

	cout << endl;

	print(root->left);
	print(root->right);
}

//count no of node in binary tree
int countNode(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		// cout << "Tree is empty!!" << endl;
		return 0;
	}

	int ans = 0;

	ans = ans + countNode(root->left);
	ans = ans + countNode(root->right);

	return (ans + 1);
}

//Print tree in inorder format
void inorder (BinaryTreeNode<int>* root) {
	if (root == NULL) {
		// cout << "Tree is empty!!" << endl;
		return;
	}

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

//Print tree in post-order format
void postorder(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		// cout << "Tree is empty!!" << endl;
		return;
	}

	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

//Helper function to construct tree using its in-order and pre-order
BinaryTreeNode<int>* helperFunction(int* in, int* pre, int in_s, int in_e, int pre_s, int pre_e) {

	if (in_s > in_e) {
		return NULL;
	}

	int rootData = pre[pre_s];
	int i;
	for (i = in_s; i <= in_e; i++) {
		if (rootData == in[i])
		{
			break;
		}
	}

	int lin_s, lin_e, lpre_s, lpre_e, rin_s, rin_e, rpre_s, rpre_e;
	lin_s = in_s;
	lin_e = i - 1;
	rin_s = i + 1;
	rin_e = in_e;
	lpre_s = pre_s + 1;
	lpre_e = lpre_s + (lin_e - lin_s);
	rpre_s = lpre_e + 1;
	rpre_e = pre_e;

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int>* leftChild = helperFunction(in, pre, lin_s, lin_e, lpre_s, lpre_e);
	BinaryTreeNode<int>* rightChild = helperFunction(in, pre, rin_s, rin_e, rpre_s, rpre_e);

	root->left = leftChild;
	root->right = rightChild;

	return root;

}


//Construct tree from given pre-order and in-order
BinaryTreeNode<int>* constructTree(int* in, int* pre, int s) {
	BinaryTreeNode<int>* root = helperFunction (in, pre, 0, s - 1, 0, s - 1);
	return root;
}

//Height of binary tree
int height (BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}

	return 1 + max (height(root->left) , height(root->right));
}

//Diameter of binary tree -- time complexcity O(n^2)
int diameter (BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}

	int op1 = height (root->left) + height (root->right);
	int op2 = diameter (root->left);
	int op3 = diameter (root->right);

	return max(op1, max(op2, op3));
}

//Diameter of binary tree -- time complexcity O(n)
pair<int, int> heightDaimeter (BinaryTreeNode<int>* root) {
	if (root == NULL) {
		pair<int, int> p;
		p = make_pair(0, 0);
		return p;
	}

	pair<int, int> p1 = heightDaimeter (root->left);
	pair<int, int> p2 = heightDaimeter (root->right);

	pair<int, int> p;
	p.first = 1 + max(p1.first, p2.first);
	p.second = max(p1.first + p2.first, max(p1.first, p2.first));

	return p;
}


int main() {

#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen ("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen ("output.txt", "w", stdout);
#endif

	/*BinaryTreeNode<int>* root = new BinaryTreeNode<int> (1);
	BinaryTreeNode<int>* l = new BinaryTreeNode<int> (2);
	BinaryTreeNode<int>* r = new BinaryTreeNode<int> (3);

	root->left = l;
	root->right = r;*/

	BinaryTreeNode<int>* root = input1();
	print1(root);
	// int n = countNode(root);
	// cout << n << endl;
	// inorder(root);
	// cout << endl;
	// postorder(root);

	// int in[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
	// int pre[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};

	// BinaryTreeNode<int>* root = constructTree(in, pre, 9);
	// print(root);

	int d = diameter(root);
	cout << d << endl;
	pair<int, int> d2 = heightDaimeter(root);
	cout << d2.second << endl;
}

