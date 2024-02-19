#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

vector<int> scores(5, 0);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	int t, g;
	cin >> t >> g;
	while (g--) {
		int t1, t2, s1, s2;
		cin >> t1 >> t2 >> s1 >> s2;
		if (s1 == s2) {
			scores[t1]++;
			scores[t2]++;
		}
		if (s1 > s2) {
			scores[t1] += 3;
		} else {
			scores[t2] += 3;
		}
	}

	// return res
	ll res = 0;
	cout << fixed << res;
	return 0;
}