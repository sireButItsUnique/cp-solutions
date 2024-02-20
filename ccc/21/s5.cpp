// partial points

#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> res(n, 1);
	// do all 2s before ones

	vector<int> x(m);
	vector<int> y(m);
	vector<int> z(m);
	for (int i = 0; i < m; i++) {
		cin >> x[i] >> y[i] >> z[i];
		x[i]--;
		y[i]--;
		if (z[i] == 2) {
			for (int j = x[i]; j <= y[i]; j++) {
				res[j] = 2;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		if (z[i] == 1) {
			bool found = false;
			for (int j = x[i]; j <= y[i]; j++) {
				if (res[j] == 1) {
					found = true;
					break;
				}
			}
			if (!found) {
				cout << "Impossible";
				return 0;
			}
		}
	}

	for (auto r : res) {
		cout << r << " ";
	}
	return 0;
}
/*
3 2
1 2 2
2 3 1
*/