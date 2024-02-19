#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	int y;
	cin >> y;
	y++;
	while (true) {
		string year = to_string(y);
		vector<bool> cnt(10, false);
		bool repeat = false;
		for (int i = 0; i < year.size(); i++) {
			if (cnt[year[i] - '0']) {
				repeat = true;
				break;
			}
			cnt[year[i] - '0'] = true;
		}
		if (!repeat) {
			cout << y;
			return 0;
		}
		y++;
	}

	// return res
	cout << -1;
	return 0;
}