#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	int m, n;
	cin >> m >> n;
	if (m == 1 && n == 1) {
		std::cout << "yes";
		return 0;
	}
	vector<vector<int>> grid(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	queue<vector<int>> bfs;
	set<int> visited;
	bfs.push({0, 0});
	while (!bfs.empty()) {
		int row = bfs.front()[0];
		int col = bfs.front()[1];

		int cap = ceil(sqrt(grid[row][col]));
		for (int i = 1; i <= cap; i++) {
			if (!(grid[row][col] % i)) {

				int x = i - 1;
				int y = (grid[row][col] / i) - 1;
				if (x < grid.size() && (y < grid[0].size())) {
					if (x == grid.size() - 1 && y == grid[0].size() - 1) {
						std::cout << "yes";
						return 0;
					}

					if (!visited.count(grid[x][y])) {
						bfs.push({x, y});
						visited.insert(grid[x][y]);
					}
				}
				if (x < grid[0].size() && (y < grid.size())) {
					if (y == grid.size() - 1 && x == grid[0].size() - 1) {
						std::cout << "yes";
						return 0;
					}

					if (!visited.count(grid[y][x])) {
						bfs.push({y, x});
						visited.insert(grid[y][x]);
					}
				}
			}
		}
		bfs.pop();
	}

	// return res
	std::cout << "no";
	return 0;
}