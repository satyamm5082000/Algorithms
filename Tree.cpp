/*
It is all about
generic tree
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
public:
	T data;
	vector<TreeNode<T>*> childern;

	TreeNode(T d)
	{
		data = d;
	}

	//to delete tree by typing "delete root" only
	~TreeNode ()
	{
		for (int i = 0; i < childern.size(); ++i)
		{
			delete childern[i];
		}
	}
};

//Take input BFS wise
TreeNode<int>* input1() {

	// cout << "Enter data" << endl;
	int rootData;
	cin >> rootData;

	queue<TreeNode<int>*> q;

	TreeNode<int>* root = new TreeNode<int> (rootData);

	//push root element in queue
	q.push(root);

	while (!q.empty())
	{
		TreeNode<int>* node = q.front ();
		q.pop ();

		// cout << "Enter no of childern" << endl;
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			//cout<<"Enter data for:"<<node->data<<" node"<<endl;
			int data;
			cin >> data;
			TreeNode<int>* newData = new TreeNode<int> (data);
			node->childern.push_back(newData);
			q.push(newData);
		}
	}

	return root;
}
//Take input DFS wise
TreeNode<int>* input() {
	// cout << "Enter data" << endl;
	int rootData;
	cin >> rootData;

	// cout << "Enter no of childern" << endl;
	int n;
	cin >> n;

	TreeNode<int>* root = new TreeNode<int> (rootData);

	for (int i = 0; i < n; i++)
	{
		TreeNode<int>* child = input();
		root->childern.push_back(child);
	}

	return root;
}

//Print BFS wise
void print1 (TreeNode<int>* root) {

	if (root == NULL) {
		cout << "Tree is Empty!!" << endl;
		return;
	}

	//Created queue and push root to queue
	queue<TreeNode<int>*> q;
	q.push(root);

	while (!q.empty()) {
		TreeNode<int>* node = q.front ();
		q.pop();

		cout << node->data << ":";

		for (int i = 0; i < node->childern.size(); i++)
		{
			cout << node->childern[i]->data << ",";
			q.push(node->childern[i]);
		}

		cout << endl;
	}
}

//Print DFS wise
void print (TreeNode<int>* root) {

	if (root == NULL) {
		cout << "Tree is Empty!!" << endl;
		return;
	}

	cout << root->data << ":" << " ";

	for (int i = 0; i < root->childern.size(); i++)
		cout << root->childern[i]->data << ",";

	cout << endl;

	for (int i = 0; i < root->childern.size(); i++)
		print(root->childern[i]);
}


//No of nodes
int nodesNumber(TreeNode<int>* root)
{
	int ans = 0;
	if (root == NULL) {
		cout << "Tree is Empty!!" << endl;
		return ans;
	}

	for (int i = 0; i < root->childern.size(); i++)
	{
		ans = ans + nodesNumber(root->childern[i]);
	}

	return ans + 1;
}

//Height of tree
int height(TreeNode<int>* root) {

	int ans = 0;
	if (root == NULL) {
		cout << "Tree is Empty!!" << endl;
		return ans;
	}

	for (int i = 0; i < root->childern.size(); i++)
	{
		int cur = height(root->childern[i]);
		if (cur > ans)
			ans = cur;
	}

	return ans + 1;
}

//Print at level K
void printLevel(TreeNode<int>* root, int k) {

	if (root == NULL)
	{
		return;
	}
	if (k == 0)
	{
		cout << root->data << endl;
		return;
	}

	for (int i = 0; i < root->childern.size(); ++i)
	{
		printLevel(root->childern[i], k - 1);
	}

	// cout << root->data << endl;

}

//Count no of leaf node
int countLeaf(TreeNode<int>* root) {
	int ans = 0;
	if (root == NULL) {
		cout << "Tree is Empty!!" << endl;
		return 0;
	}

	if (root->childern.size() == 0)
		return 1;

	for (int i = 0; i < root->childern.size(); i++)
	{
		ans = ans + countLeaf(root -> childern[i]);
	}

	return ans;
}

//Print in pre-order
void printPreorder(TreeNode<int>* root) {
	if (root == NULL)
	{
		cout << "Tree is empty!!" << endl;
		return;
	}

	cout << root->data << " ";

	for (int i = 0; i < root->childern.size(); i++)
	{
		printPreorder(root->childern[i]);
	}
}

//Print in post-order
void printPostorder(TreeNode<int>* root) {
	if (root == NULL)
	{
		cout << "Tree is empty!!" << endl;
		return;
	}

	for (int i = 0; i < root->childern.size(); ++i)
	{
		printPostorder(root->childern[i]);
	}

	cout << root->data << " ";
}

//Delete Tree (kind of post-order method)
/*
void deleteTree(TreeNode<int>* root) {

	for (int i = 0; i < root->childern.size(); i++)
	{
		deleteTree(root->childern[i]);
	}

	delete root;
}
*/
int main ()
{
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen ("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen ("output.txt", "w", stdout);
#endif

	TreeNode<int>* root = input1();
	// print1 (root);
	int count = nodesNumber(root);
	// cout << count << endl;
	int h = height(root);
	// cout << h << endl;
	// printLevel(root, 2);
	int cl = countLeaf(root);
	// cout << cl << endl;
	printPreorder(root);
	cout << endl;
	printPostorder(root);
	// deleteTree(root);
	delete root;
	// printPostorder(root);
}
