#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

int t, n;
int hay[100001];

int main() {
	cin >> t;
	while (t--) {
		set<int> res;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> hay[i];
		}
		if (hay[0] == hay[1]) {
			res.insert(hay[0]);
		}
		for (int i = 2; i < n; i++) {
			if (hay[i] == hay[i - 1] || hay[i] == hay[i - 2]) {
				res.insert(hay[i]);
			}
		}
		if (!res.size()) {
			cout << "-1";
		} else {
			for (auto itr = res.begin(); itr != res.end(); itr++) {
				cout << *itr;
				if (next(itr) != res.end()) {
					cout << " ";
				}
			}
		}
		cout << endl;
	}
	return 0;
}