#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, res;
	cin >> n >> m;
	vector<int> a(n, true);
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}

	for (int j = 0; j < m; j++) {
		int r;
		cin >> r;
		vector<int> b;

		for (int i = 0; i < a.size(); i++) {
			if ((i + 1) % r != 0) {
				b.push_back(a[i]);
			}
		}

		a = b;
	}

	for (auto x : a) {
		cout << x << endl;
	}

	return 0;
}