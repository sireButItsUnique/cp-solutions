#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> a(n);
	unordered_map<string, string> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		string buf;
		cin >> buf;
		if (buf == a[i]) {
			cout << "bad";
			return 0;
		}

		if (m.find(a[i]) != m.end()) {
			if (m[a[i]] != buf) {
				cout << "bad";
				return 0;
			}
		}
		m[buf] = a[i];
	}
	cout << "good";
	return 0;
}