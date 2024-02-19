#include <bits/stdc++.h>
using namespace std;

int main() {
	int M, N, K;
	cin >> M >> N >> K;
	vector<bool> X(M, false);
	vector<bool> Y(N, false);

	for (int i = 0; i < K; i++) {
		char dir;
		int pos;
		cin >> dir >> pos;

		if (dir == 'R') {
			X[pos - 1] = !X[pos - 1];
		} else {
			Y[pos - 1] = !Y[pos - 1];
		}
	}

	int cnt = 0;
	for (auto x : X) {
		for (auto y : Y) {
			// cout << ((y || x) && (!y || !x));
			cnt += ((y || x) && (!y || !x));
		}
		// cout << endl;
	}

	cout << cnt;
	return 0;
}