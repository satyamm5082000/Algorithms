#include <bits/stdc++.h>
using namespace std;

void build(int* ar, int* segemenTree, int start, int end, int treeNode)
{
	if (start == end)
	{
		segemenTree[treeNode] = ar[end];
		return;
	}
	int mid = (start + end) / 2;
	build(ar, segemenTree, start, mid, 2 * treeNode);
	build(ar, segemenTree, mid + 1, end, 2 * treeNode + 1);

	segemenTree[treeNode] = segemenTree[2 * treeNode] + segemenTree[2 * treeNode + 1];

	return;
}

void update(int* ar, int* segemenTree, int start, int end, int treeNode, int idx, int value)
{
	if (start == end)
	{
		ar[idx] = value;
		segemenTree[treeNode] = value;
		return;
	}
	int mid = (start + end) / 2;

	if (idx <= mid)
	{
		update(ar, segemenTree, start, mid, 2 * treeNode, idx, value);
	}
	else
	{
		update(ar, segemenTree, mid + 1, end, 2 * treeNode + 1, idx, value);
	}

	segemenTree[treeNode] = segemenTree[2 * treeNode] + segemenTree[2 * treeNode + 1];

	return;
}

int range(int* ar, int* segemenTree, int start, int end, int treeNode, int l, int r)
{
	if (r < start || l > end)
		return 0;

	if (start >= l && end <= r)//error point
		return segemenTree[treeNode];

	int mid = (start + end) / 2;

	int ans1 = range(ar, segemenTree, start, mid, 2 * treeNode, l, r);
	int ans2 = range(ar, segemenTree, mid + 1, end, 2 * treeNode + 1, l, r);

	return (ans1 + ans2);
}


int main()
{
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen ("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen ("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	int ar[n];
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
	}

	int segemenTree[4 * n];
	memset(segemenTree, -1, sizeof(segemenTree));
	build(ar, segemenTree, 0, n - 1, 1);
	for (int i = 0; i < 4 * n; i++)
	{
		cout << segemenTree[i] << " ";
	}
	cout << endl;
	update(ar, segemenTree, 0, n - 1, 1, 2, 10);
	for (int i = 0; i < 4 * n; i++)
	{
		cout << segemenTree[i] << " ";
	}
	cout << endl;
	int ans = range(ar, segemenTree, 0, n - 1, 1, 1, 4);
	cout << ans << endl;
}
