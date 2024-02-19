#include <bits/stdc++.h>
using namespace std;

// 3 1 4 8 5 9 2
// int calc(int size, int start, vector<int> &hills) {
// 	int res = 0;
// 	for (int i = 0; i < size >> 1; i++) {
// 		res += abs(hills[start + i] - hills[start + size - i - 1]);
// 	}
// 	return res;
// }

int main() {
	int n;
	cin >> n;
	vector<int> hills(n);
	vector<int> res(n, INT_MAX);
	for (int i = 0; i < n; i++) {
		cin >> hills[i];
	}

	// calc odd res w/ middle at i
	for (int i = 0; i < n; i++) {
		int score = 0;
		for (int j = 0; j < min(i + 1, n - i); j++) {
			int start = i - j;
			int size = (j << 1) + 1;
			score += abs(hills[i - j] - hills[i + j]);
			res[size - 1] = min(res[size - 1], score);
		}
	}

	// calc even res w/ middle at i and i + 1
	for (int i = 0; i < n; i++) {
		int score = 0;
		for (int j = 0; j < min(i + 1, n - i - 1); j++) {
			int start = i - j;
			int size = (j << 1) + 2;
			score += abs(hills[i - j] - hills[i + 1 + j]);
			res[size - 1] = min(res[size - 1], score);
		}
	}

	// cout
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	return 0;
}