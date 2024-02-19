#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

long long calc(long long c, int n, vector<int> &pos, vector<int> &w,
			   vector<int> &d) {
	long long res = 0;
	for (int i = 0; i < n; i++) {
		if (c > pos[i]) {
			res += w[i] * max(c - (pos[i] + d[i]), 0LL);
		} else {
			res += w[i] * max((pos[i] - d[i]) - c, 0LL);
		}
	}
	// cout << "c = " << c << ": " << res << endl;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> pos(n);
	vector<int> w(n);
	vector<int> d(n);
	long long lower = INT_MAX;
	long long upper = 0;
	for (int i = 0; i < n; i++) {
		cin >> pos[i] >> w[i] >> d[i];
		lower = min(lower, (long long)pos[i] + d[i]);
		upper = max(upper, (long long)pos[i] - d[i]);
	}

	// bin search for res
	while (lower < upper) {

		long long mid = (lower + upper) >> 1;

		long long cur = calc(mid, n, pos, w, d);
		long long left = calc(mid - 1, n, pos, w, d);
		long long right = calc(mid + 1, n, pos, w, d);

		if (cur < left && cur < right) {
			lower = mid;
			upper = mid;
			break;
		}

		// go left
		if (left < right) {
			upper = mid;
		}
		// go right
		else {
			lower = mid + 1;
		}
	}

	long long res = calc(lower, n, pos, w, d);
	for (int i = lower - 10; i < lower + 10; i++) {
		res = min(res, calc(i, n, pos, w, d));
	}

	cout << fixed << res;
	return 0;
}