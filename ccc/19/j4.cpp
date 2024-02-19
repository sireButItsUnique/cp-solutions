#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	bool h = false;
	bool v = false;
	for (auto c : s) {
		if (c == 'H') {
			h = !h;
		} else {
			v = !v;
		}
	}

	if (h && v) {
		cout << "4 3\n2 1";
		return 0;
	}
	if (h) {
		cout << "3 4\n1 2";
		return 0;
	}
	if (v) {
		cout << "2 1\n4 3";
		return 0;
	}
	cout << "1 2\n 3 4";

	return 0;
}