#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

int n;
vector<vector<int>> table;
bool check() {
	// check rows
	for (int row = 0; row < n; row++) {
		for (int i = 1; i < n; i++) {
			if (table[row][i - 1] >= table[row][i]) {
				return false;
			}
		}
	}

	// check cols
	for (int col = 0; col < n; col++) {
		for (int i = 1; i < n; i++) {
			if (table[i - 1][col] >= table[i][col]) {
				return false;
			}
		}
	}
	return true;
}

void rotate() {
	for (int x = 0; x < n / 2; x++) {
		for (int y = x; y < n - x - 1; y++) {
			int tmp = table[x][y];

			// Move values from right to top
			table[x][y] = table[y][n - 1 - x];

			// Move values from bottom to right
			table[y][n - 1 - x] = table[n - 1 - x][n - 1 - y];

			// Move values from left to bottom
			table[n - 1 - x][n - 1 - y] = table[n - 1 - y][x];

			// Assign temp to left
			table[n - 1 - y][x] = tmp;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	cin >> n;
	table = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> table[i][j];
		}
	}

	// calc
	while (!check()) {
		rotate();
	}

	// return res
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << table[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}