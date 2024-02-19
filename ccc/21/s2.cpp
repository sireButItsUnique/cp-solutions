#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n, k;
	cin >> m >> n >> k;
	vector<bool> rows(m, false);
	vector<bool> cols(n, false);

	while (k--) {
		char c;
		int num;
		cin >> c >> num;
		if (c == 'R') {
			rows[num - 1] = !rows[num - 1];
		} else {
			cols[num - 1] = !cols[num - 1];
		}
	}

	int rSum = 0;
	for (int i = 0; i < m; i++) {
		rSum += rows[i];
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (cols[i]) {
			res += m - rSum;
		} else {
			res += rSum;
		}
	}
	cout << fixed << res;
	return 0;
}