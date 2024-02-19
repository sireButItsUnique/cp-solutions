#include <bits/stdc++.h>
using namespace std;

int main() {
	string l, s;
	cin >> l >> s;

	if (l.find(s) != string::npos) {
		cout << "yes";
		return 0;
	}
	for (auto useless : s) {
		rotate(s.begin(), s.begin() + 1, s.end());
		if (l.find(s) != string::npos) {
			cout << "yes";
			return 0;
		}
	}

	cout << "no";
	return 0;
}