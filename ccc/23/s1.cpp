#include <bits/stdc++.h>
using namespace std;

int main() {
	int cnt = 0;
	int intersect = 0;
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i]) {
			cnt++;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		if (b[i]) {
			cnt++;
		}
	}
	for (int i = 1; i < n; i++) {
		if (a[i] && a[i - 1]) {
			intersect++;
		}
		if (b[i] && b[i - 1]) {
			intersect++;
		}
	}
	for (int i = 0; i < n; i += 2) {
		if (a[i] && b[i]) {
			intersect++;
		}
	}
	cout << ((3 * cnt) - (2 * intersect));
	return 0;
}