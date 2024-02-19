#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	unordered_map<char, int> cnt;
	cnt['L'] = 0;
	cnt['M'] = 0;
	cnt['S'] = 0;
	for (auto c : s) {
		cnt[c]++;
	}

	int nLs = 0;
	int nMs = 0;
	int eLs = 0;
	int eMs = 0;
	for (int i = 0; i < s.size(); i++) {
		// in the L zone
		if (i < cnt['L']) {
			if (s[i] != 'L') {
				nLs++;
				if (s[i] == 'M') {
					eMs++;
				}
			}
		}

		// in the M zone
		else if (i < cnt['L'] + cnt['M']) {
			if (s[i] != 'M') {
				nMs++;
				if (s[i] == 'L') {
					eLs++;
				}
			}
		}
	}

	// cout << "missing:\n";
	// for (auto m: miss) {
	//     cout << m.first << ": " << m.second << endl;
	// }

	// cout << "extra:\n";
	// for (auto e: extra) {
	//     cout << e.second << endl;
	// }

	cout << nLs + nMs - min(eLs, eMs);
	// count how many are "missing"
	// count how many are "extras"
	// get min/max i forgot

	return 0;
}