#include <bits/stdc++.h>
using namespace std;

//BFS
void bfs(int** graph, int v, int sv, int* vis) {
	queue<int> q;
	q.push(sv);
	vis[sv] = 1;

	while (!q.empty()) {
		int cur = q.front ();
		q.pop();
		cout << cur << " ";
		for (int i = 0; i < v; i++) {
			if (i == cur) {
				continue;
			}
			if (graph[cur][i] == 1 && !vis[i]) {
				q.push(i);
				vis[i] = 1;
			}
		}
	}
}

//DFS
void dfs (int** graph, int v, int sv, int* vis) {
	cout << sv << " ";
	vis[sv] = 1;

	for (int i = 0; i < v; i++) {
		if (i == sv) {
			continue;
		}
		if (graph[sv][i] == 1 && !vis[i]) {
			dfs(graph, v, i, vis);
		}
	}
}

//check if graph is connected or not
void dfs1 (int** graph, int v, int sv, int* vis) {
	// cout << sv << " ";
	vis[sv] = 1;

	for (int i = 0; i < v; i++) {
		if (i == sv) {
			continue;
		}
		if (graph[sv][i] == 1 && !vis[i]) {
			dfs1(graph, v, i, vis);
		}
	}
}

//find all the connected component in vector
vector<int> bfs1 (int** graph, int v, int sv, int* vis) {
	queue<int> q;
	q.push(sv);
	vector<int> ans;
	// v.push_back(sv);
	vis[sv] = 1;

	while (!q.empty()) {
		int cur = q.front ();
		q.pop();
		ans.push_back(cur);
		for (int i = 0; i < v; i++) {
			if (i == cur) {
				continue;
			}
			if (graph[cur][i] == 1 && !vis[i]) {
				q.push(i);
				vis[i] = 1;
			}
		}
	}

	return ans;
}

//haspath function using DFS
bool haspath(int** graph, int v, int s, int e, int* vis) {
	for (int i = 0; i < v; i++) {
		if (graph[s][i] == 1 && i == e)
			return true;
	}

	vis[s] = 1;

	for (int i = 0; i < v; i++) {
		if (graph[s][i] == 1 && !vis[i]) {
			bool ans = haspath(graph, v, i, e, vis);
			if (ans)
				return true;
		}
	}

	return false;
}

//get path using DFS
bool getpathDFS (int** graph, int v, int s, int e, int* vis, vector<int> &vv) {
	if (s == e) {
		vv.push_back(s);
		return true;
	}

	vis[s] = 1;

	for (int i = 0; i < v; i++) {
		if (graph[s][i] == 1 && !vis[i]) {
			bool ans = getpathDFS(graph, v, i, e, vis, vv);

			if (ans) {
				vv.push_back(s);
				return true;
			}
		}
	}

	return false;
}

//get path using BFS
bool getpathBFS (int** graph, int v, int s, int e, int* vis, vector<int> &vv) {
	queue<int> q;
	q.push(s);
	vis[s] = 1;
	map<int, int> m;
	int f = 0;
	while (!q.empty()) {
		int c = q.front();
		q.pop();

		for (int i = 0; i < v; i++) {
			if (graph[c][i] == 1 && !vis[i]) {
				q.push(i);
				vis[i] = 1;
				m[i] = c;
				if (i == e) {
					// cout << true << endl;
					f = 1;
					break;
				}
			}
		}

		if (f == 1) {
			// cout << true << endl;
			break;
		}
	}

	if (f == 0) {
		// cout << true << endl;
		return false;
	}

	// for (auto it = m.begin (); it != m.end (); it++) {
	// 	cout << it->first << " " << it->second << endl;
	// }

	int ff = e;
	while (ff != s) {
		vv.push_back(ff);
		auto it = m.find(ff);
		ff = (*it).second;
	}

	vv.push_back(s);

	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen ("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen ("output.txt", "w", stdout);
#endif
	//No of vertix and edges
	int v, e;
	cin >> v >> e;

	//Created adjacency Martix
	int** graph = new int*[v];

	for (int i = 0; i < v; i++)
	{
		graph[i] = new int[v];
		for (int j = 0; j < v; j++)
		{
			graph[i][j] = 0;
		}
	}

	for (int i = 0; i < e; i++)
	{
		int s, e;
		cin >> s >> e;
		graph[s][e] = 1;
		graph[e][s] = 1;
	}

	int* vis = new int[v];
	// memset(v, 0, sizeof(v));
	for (int i = 0; i < v; i++) {
		vis[i] = 0;
	}

	vector<std::vector<int> > ans;

	//Print DFS
	// cout << "DFS" << endl;
	// for (int i = 0; i < v; i++) {
	// 	if (!vis[i])
	// 		dfs(graph, v, i, vis);
	// }

	// cout << endl;
	// for (int i = 0; i < v; i++) {
	// 	vis[i] = 0;
	// }

	//Print BFS
	// cout << "BFS" << endl;
	// for (int i = 0; i < v; i++) {
	// 	if (!vis[i])
	// 		bfs(graph, v, i, vis);
	// }

	// if (haspath(graph, v, 0, 7, vis)) {
	// 	cout << "YES" << endl;
	// }
	// else {
	// 	cout << "NO" << endl;
	// }

	// vector<int> vv;

	// if (getpathDFS(graph, v, 0, 8, vis, vv)) {
	// 	cout << "YES" << endl;
	// 	for (int i = vv.size () - 1; i >= 0; i--) {
	// 		cout << vv[i] << " ";
	// 	}

	// cout << endl;
	// }
	// else {
	// 	cout << "NO" << endl;
	// }

	// if (getpathBFS(graph, v, 0, 7, vis, vv)) {
	// 	cout << "YES" << endl;
	// 	for (int i = vv.size() - 1; i >= 0; i--) {
	// 		cout << vv[i] << " ";
	// 	}

	// 	cout << endl;
	// } else {
	// 	cout << "NO" << endl;
	// }

	// dfs1(graph, v, 0, vis);
	// cout << endl;
	for (int i = 0; i < v; i++) {
		if (!vis[i]) {
			vector<int> vv = bfs1(graph, v, i, vis);
			ans.push_back(vv);
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}

		cout << endl;
	}

	// cout << "Connected" << endl;

	return 0;
}
