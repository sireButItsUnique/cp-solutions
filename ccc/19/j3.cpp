#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		int num = 0;
		char last = s[0];
		for (auto c : s) {
			if (c == last) {
				num++;
			} else {
				cout << num << " " << last << " ";
				num = 1;
				last = c;
			}
		}
		cout << num << " " << last << " " << endl;
	}

	return 0;
}