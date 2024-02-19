#include <bits/stdc++.h>
using namespace std;
/*
c b b b
b a a a
b a a a
b a a a
*/

void print(vector<string> &grid) {
	for (int i = 0; i < grid.size(); i++) {
		cout << grid[i] << endl;
	}
}

int main() {
	int n, m, r, c;
	cin >> n >> m >> r >> c;
	vector<string> grid(n, string(m, 'a'));

	// edge case
	if (r >= n || c >= m) {

		// flood
		if (r >= n && c >= m) {
			print(grid);
			return 0;
		}

		// flood one row/col
		if (!r || !c) {
			if (!r) {
				for (int i = 0; i < n; i++) {
					grid[i][0] = 'b';
				}
			} else {
				grid[0] = string(m, 'b');
			}
			print(grid);
			return 0;
		}

		// flood multiple -> if even always possible, if odd only possible if
		// full thing is odd
		if (r == n) { // flood columns
			if (c % 2 == 0) {
				grid[0] = string(m, 'b');
				for (int i = 0; i < (c >> 1); i++) {
					grid[0][i] = 'a';
					grid[0][m - i - 1] = 'a';
				}
				print(grid);
				return 0;
			} else if (m % 2) {
				grid[0] = string(m, 'b');
				for (int i = 0; i < (c >> 1); i++) {
					grid[0][i] = 'a';
					grid[0][m - i - 1] = 'a';
				}
				grid[0][m >> 1] = 'a';
				print(grid);
				return 0;
			}
		}
		if (c == m) { // flood rows
			if (r % 2 == 0) {
				for (int i = 0; i < n; i++) {
					grid[i][0] = 'b';
				}
				for (int i = 0; i < (r >> 1); i++) {
					grid[i][0] = 'a';
					grid[n - i - 1][0] = 'a';
				}
				print(grid);
				return 0;
			} else if (n % 2) {
				for (int i = 0; i < n; i++) {
					grid[i][0] = 'b';
				}
				for (int i = 0; i < (r >> 1); i++) {
					grid[i][0] = 'a';
					grid[n - i - 1][0] = 'a';
				}
				grid[n >> 1][0] = 'a';
				print(grid);
				return 0;
			}
		}

		cout << "IMPOSSIBLE";
		return 0;
	}

	// set up grid
	grid[0] = string(m, 'b');
	for (int i = 0; i < n; i++) {
		grid[i][0] = 'b';
	}
	grid[0][0] = 'c';

	// flip
	for (int i = 1; i < n; i++) {
		if (r) {
			grid[i][0] = 'a';
			r--;
		} else {
			break;
		}
	}
	for (int i = 1; i < m; i++) {
		if (c) {
			grid[0][i] = 'a';
			c--;
		} else {
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << grid[i] << endl;
	}
	return 0;
}