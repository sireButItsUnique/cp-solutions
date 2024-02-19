#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

int n, m;
vector<string> grid;
vector<vector<int>> visited;
queue<vector<int>> bfs;

bool initCamera(int n, int m, vector<string> &grid, vector<vector<int>> &visited) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 'W') {
				visited[i][j] = -1;
			}
			if (grid[i][j] == 'C') {
				visited[i][j] = -1;

				int dist = 1;
				while (grid[i + dist][j] != 'W') {
					if (grid[i + dist][j] == 'S') {
						return true;
					}
					if (grid[i + dist][j] == '.') {
						visited[i + dist][j] = -1;
					}
					dist++;
				}
				dist = 1;
				while (grid[i - dist][j] != 'W') {
					if (grid[i - dist][j] == 'S') {
						return true;
					}
					if (grid[i - dist][j] == '.') {
						visited[i - dist][j] = -1;
					}
					dist++;
				}
				dist = 1;
				while (grid[i][j + dist] != 'W') {
					if (grid[i][j + dist] == 'S') {
						return true;
					}
					if (grid[i][j + dist] == '.') {
						visited[i][j + dist] = -1;
					}
					dist++;
				}
				dist = 1;
				while (grid[i][j - dist] != 'W') {
					if (grid[i][j - dist] == 'S') {
						return true;
					}
					if (grid[i][j - dist] == '.') {
						visited[i][j - dist] = -1;
					}
					dist++;
				}
			}
		}
	}
	return false;
}

void rec(int dist, int row, int col) {

	// while its still on converyer
	while (!visited[row][col]) {
		// cout << "visiting " << row << ", " << col << " with dist " << dist << endl;
		if (grid[row][col] == '.') {
			visited[row][col] = dist;
			bfs.push({dist, row, col});
			return;
		}

		visited[row][col] = dist;
		if (grid[row][col] == 'D') {
			row++;
		} else if (grid[row][col] == 'U') {
			row--;
		} else if (grid[row][col] == 'R') {
			col++;
		} else if (grid[row][col] == 'L') {
			col--;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	int n, m;
	cin >> n >> m;
	grid = vector<string>(n);
	visited = vector<vector<int>>(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 'S') {
				visited[i][j] = 1;
				bfs.push({1, i, j});
				break;
			}
		}
	}

	// do all camera work
	if (initCamera(n, m, grid, visited)) {

		// exit early if starting spot is blocked
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == '.') {
					cout << "-1";
					cout << endl;
				}
			}
		}
		return 0;
	}

	// calc w/ bfs
	while (!bfs.empty()) {
		int dist = bfs.front()[0];
		int row = bfs.front()[1];
		int col = bfs.front()[2];
		bfs.pop();
		// cout << "visiting " << row << ", " << col << " with dist " << dist << endl;

		// try moving in all 4 dirs
		if (!visited[row + 1][col]) {
			if (grid[row + 1][col] == '.') {
				visited[row + 1][col] = dist + 1;
				bfs.push({dist + 1, row + 1, col});
			} else {
				rec(dist + 1, row + 1, col);
			}
		}

		if (!visited[row - 1][col]) {
			if (grid[row - 1][col] == '.') {
				visited[row - 1][col] = dist + 1;
				bfs.push({dist + 1, row - 1, col});
			} else {
				rec(dist + 1, row - 1, col);
			}
		}

		if (!visited[row][col + 1]) {
			if (grid[row][col + 1] == '.') {
				visited[row][col + 1] = dist + 1;
				bfs.push({dist + 1, row, col + 1});
			} else {
				rec(dist + 1, row, col + 1);
			}
		}

		if (!visited[row][col - 1]) {
			if (grid[row][col - 1] == '.') {
				visited[row][col - 1] = dist + 1;
				bfs.push({dist + 1, row, col - 1});
			} else {
				rec(dist + 1, row, col - 1);
			}
		}
	}

	// return res
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '.') {
				if (visited[i][j] > 0) {
					cout << (visited[i][j] - 1);
				} else {
					cout << "-1";
				}
				cout << endl;
			}
		}
	}
	return 0;
}