#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>> flowers, int n) {
	for (int j = 0; j < n; j++) {
		if (flowers[0][j] <= flowers[0][j - 1]) {
			// cout << "issue on row 0" << endl;
			return false;
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (flowers[i][j] <= flowers[i - 1][j]) {
				// cout << "issue on col " << j << endl;
				return false;
			}

			if (flowers[i][j] <= flowers[i][j - 1]) {
				cout << "issue on row " << i << endl;
				return false;
			}
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;

	vector<int> buf(n);
	vector<vector<int>> flowers(n, buf);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> flowers[i][j];
		}
	}

	if (check(flowers, n)) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << flowers[i][j] << " ";
			}
			cout << endl;
		}
		return 0;
	}

	for (int i = 0; i < n / 2; i++) {
		for (int j = i; j < n - i - 1; j++) {
			int temp = flowers[i][j];
			flowers[i][j] = flowers[n - 1 - j][i];
			flowers[n - 1 - j][i] = flowers[n - 1 - i][n - 1 - j];
			flowers[n - 1 - i][n - 1 - j] = flowers[j][n - 1 - i];
			flowers[j][n - 1 - i] = temp;
		}
	}

	if (check(flowers, n)) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << flowers[i][j] << " ";
			}
			cout << endl;
		}
		return 0;
	}

	for (int i = 0; i < n / 2; i++) {
		for (int j = i; j < n - i - 1; j++) {
			int temp = flowers[i][j];
			flowers[i][j] = flowers[n - 1 - j][i];
			flowers[n - 1 - j][i] = flowers[n - 1 - i][n - 1 - j];
			flowers[n - 1 - i][n - 1 - j] = flowers[j][n - 1 - i];
			flowers[j][n - 1 - i] = temp;
		}
	}

	if (check(flowers, n)) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << flowers[i][j] << " ";
			}
			cout << endl;
		}
		return 0;
	}

	for (int i = 0; i < n / 2; i++) {
		for (int j = i; j < n - i - 1; j++) {
			int temp = flowers[i][j];
			flowers[i][j] = flowers[n - 1 - j][i];
			flowers[n - 1 - j][i] = flowers[n - 1 - i][n - 1 - j];
			flowers[n - 1 - i][n - 1 - j] = flowers[j][n - 1 - i];
			flowers[j][n - 1 - i] = temp;
		}
	}

	if (check(flowers, n)) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << flowers[i][j] << " ";
			}
			cout << endl;
		}
		return 0;
	}

	return 0;
}