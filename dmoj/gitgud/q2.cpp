#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;

vector<vector<vector<int>>> grid(5, vector<vector<int>>(4, vector<int>(4)));
int calc(vector<vector<int>> board, int ply) {

	// init queue
	int res = 0;
	queue<pair<int, vector<vector<int>>>> bfs;
	set<vector<vector<int>>> visited;
	bfs.push({0, board});
	visited.insert(board);

	// bfs every possible board
	while (bfs.size()) {
		// cur highest ele
		set<int> cnt;
		for (int row = 0; row < 4; row++) {
			for (int col = 0; col < 4; col++) {
				res = max(res, bfs.front().second[row][col]);
			}
		}

		// up
		vector<vector<int>> shift = bfs.front().second;
		for (int row = 1; row < 4; row++) {
			for (int col = 0; col < 4; col++) {
				if (shift[row - 1][col] == shift[row][col]) {
					shift[row - 1][col] *= 2;
					shift[row][col] = 0;
				} else if (!shift[row - 1][col]) {
					shift[row - 1][col] = shift[row][col];
					shift[row][col] = 0;
				}
			}
		}
		if (bfs.front().first < ply && !visited.count(shift)) {
			visited.insert(shift);
			bfs.push({bfs.front().first + 1, shift});
		}
		// down
		shift = bfs.front().second;
		for (int row = 2; row >= 0; row--) {
			for (int col = 0; col < 4; col++) {
				if (shift[row + 1][col] == shift[row][col]) {
					shift[row + 1][col] *= 2;
					shift[row][col] = 0;
				} else if (!shift[row + 1][col]) {
					shift[row + 1][col] = shift[row][col];
					shift[row][col] = 0;
				}
			}
		}
		if (bfs.front().first < ply && !visited.count(shift)) {
			visited.insert(shift);
			bfs.push({bfs.front().first + 1, shift});
		}

		// left
		shift = bfs.front().second;
		for (int row = 0; row < 4; row++) {
			for (int col = 1; col < 4; col++) {
				if (shift[row][col - 1] == shift[row][col]) {
					shift[row][col - 1] *= 2;
					shift[row][col] = 0;
				} else if (!shift[row][col - 1]) {
					shift[row][col - 1] = shift[row][col];
					shift[row][col] = 0;
				}
			}
		}
		if (bfs.front().first < ply && !visited.count(shift)) {
			visited.insert(shift);
			bfs.push({bfs.front().first + 1, shift});
		}

		// right
		shift = bfs.front().second;
		for (int row = 0; row < 4; row++) {
			for (int col = 2; col >= 0; col--) {
				if (shift[row][col + 1] == shift[row][col]) {
					shift[row][col + 1] *= 2;
					shift[row][col] = 0;
				} else if (!shift[row][col + 1]) {
					shift[row][col + 1] = shift[row][col];
					shift[row][col] = 0;
				}
			}
		}
		if (bfs.front().first < ply && !visited.count(shift)) {
			visited.insert(shift);
			bfs.push({bfs.front().first + 1, shift});
		}

		bfs.pop();
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	for (int i = 0; i < 5; i++) {
		for (int row = 0; row < 4; row++) {
			for (int col = 0; col < 4; col++) {
				cin >> grid[i][row][col];
			}
		}
	}
	// return res
	for (int i = 0; i < 5; i++) {
		ll res = calc(grid[i], 12);
		cout << fixed << res << endl;
	}
	return 0;
}