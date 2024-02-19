#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &graph, int x, int y) {
	// exit upon hitting the thing
	if (x + 1 == graph[0].size() && y + 1 == graph.size()) {
		cout << "yes";
		return true;
	}

	int n = graph[y][x];
	// cout << "visiting " << n << endl;
	graph[y][x] = -1;

	// get all factors
	for (int i = 1; i <= sqrt(n); i++) {
		if ((n % i) == 0) {
			int n1 = i;
			int n2 = n / i;
			n1--;
			n2--;

			// dfs futher
			if (n2 < graph.size() && n1 < graph[0].size()) {
				if ((graph[n2][n1]) != -1) {
					if (dfs(graph, n1, n2)) {
						return true;
					}
				}
			}

			if (n2 < graph[0].size() && n1 < graph.size()) {
				if ((graph[n1][n2]) != -1) {
					if (dfs(graph, n2, n1)) {
						return true;
					}
				}
			}
		}
	}

	return false;
}

int main() {
	// getting input
	int h, w;
	cin >> h >> w;
	vector<int> buf(w);
	vector<vector<int>> graph(h, buf);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> graph[i][j];
		}
	}

	bool res = dfs(graph, 0, 0);
	if (!res) {
		cout << "no";
	}
	return 0;
}