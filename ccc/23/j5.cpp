#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

vector<vector<char>> grid;
string word;

bool straight(int row, int col, int idx, int x, int y) {

	// outta bounds/not match
	if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
		return false;
	}
	if (grid[row][col] != word[idx]) {
		return false;
	}
	// cout << "straight: " << row << ", " << col << " on idx " << idx << endl;

	// hit end
	if (idx == word.size() - 1) {
		// cout << "ended\n";
		return true;
	}

	// keep recing
	return straight(row + y, col + x, idx + 1, x, y);
}

int rec(int row, int col, int idx, int x, int y) {

	// outta bounds/not match
	if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
		return 0;
	}

	if (grid[row][col] != word[idx]) {
		return 0;
	}
	// cout << "rec: " << row << ", " << col << " on idx " << idx << endl;

	// hit end
	if (idx >= word.size() - 1) {
		// cout << "ended\n";
		return 1;
	}

	// keep recing
	int res = 0;
	res += rec(row + y, col + x, idx + 1, x, y);

	// turns
	if ((x == 0) || (y == 0)) {
		if (x) {
			res += straight(row + 1, col, idx + 1, 0, 1);
			res += straight(row - 1, col, idx + 1, 0, -1);
			// cout << "went up/down" << endl;
		} else {
			res += straight(row, col + 1, idx + 1, 1, 0);
			res += straight(row, col - 1, idx + 1, -1, 0);
		}
	} else {
		if (x == y) {
			res += straight(row - 1, col + 1, idx + 1, 1, -1);
			res += straight(row + 1, col - 1, idx + 1, -1, 1);
		} else {
			res += straight(row + 1, col + 1, idx + 1, 1, 1);
			res += straight(row - 1, col - 1, idx + 1, -1, -1);
		}
	}

	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	int r, c;
	cin >> word >> r >> c;
	grid = vector<vector<char>>(r, vector<char>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> grid[i][j];
		}
	}

	// start from every idx
	ll res = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (grid[i][j] == word[0]) {
				res += rec(i + 1, j, 1, 0, 1);
				res += rec(i - 1, j, 1, 0, -1);
				res += rec(i, j + 1, 1, 1, 0);
				res += rec(i, j - 1, 1, -1, 0);
				res += rec(i + 1, j + 1, 1, 1, 1);
				res += rec(i + 1, j - 1, 1, -1, 1);
				res += rec(i - 1, j + 1, 1, 1, -1);
				res += rec(i - 1, j - 1, 1, -1, -1);
				// cout << res << ";\n";
			}
		}
	}

	// return res
	cout << fixed << res;
	return 0;
}

/*
NATURE
6
9
N A T S F E G Q N
S A I B M R H F A
C F T J C U C L T
K B H U P T A N U
D P R R R J D I R
I E E K M E G B E
*/