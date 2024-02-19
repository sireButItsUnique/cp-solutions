#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	double res = 0;
	int n;
	cin >> n;

	vector<int> h(n + 1);
	for (int i = 0; i <= n; i++) {
		cin >> h[i];
	}
	for (int i = 0; i < n; i++) {
		int w;
		cin >> w;
		res += w * min(h[i], h[i + 1]);
		res += w * 0.5 * abs(h[i] - h[i + 1]);
	}

	cout << fixed << res;
	return 0;
}