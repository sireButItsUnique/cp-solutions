#include <bits/stdc++.h>
using namespace std;

int main() {
	// first we get the input as an adjacency list
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n; i++) {
		int e;
		cin >> e;
		vector<int> edges(e);
		for (int j = 0; j < e; j++) {
			cin >> edges[j];
			edges[j]--;
		}
		adj[i] = edges;
	}

	// then we do bfs traversal; keeping track of the lowest depth leaf
	queue<pair<int, int>> bfsQueue;
	vector<bool> visited(n, false);
	int leaf = -1;

	bfsQueue.push(pair<int, int>(0, 1));
	while (!bfsQueue.empty()) {
		// getting current node
		pair<int, int> cur = bfsQueue.front();
		bfsQueue.pop();
		visited[cur.first] = true;

		// seeing if its a leaf node
		if (adj[cur.first].size() == 0 && leaf == -1) {
			leaf = cur.second;
		}

		// visiting other neighbour nodes
		for (int i = 0; i < adj[cur.first].size(); i++) {
			if (!visited[adj[cur.first][i]]) {
				bfsQueue.push(
					pair<int, int>(adj[cur.first][i], cur.second + 1));
			}
		}
	}

	// finally check if everything was visited
	for (auto v : visited) {
		if (!v) {
			cout << "N\n" << leaf;
			return 0;
		}
	}

	cout << "Y\n" << leaf;
	return 0;
}