#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<char, int> m;
	m['A'] = 0;
	m['B'] = 0;

	int n;
	string s;
	cin >> n >> s;
	for (auto c : s) {
		m[c]++;
	}

	if (m['A'] > m['B']) {
		cout << "A";
	} else if (m['A'] < m['B']) {
		cout << 'B';
	} else {
		cout << "Tie";
	}
	return 0;
}