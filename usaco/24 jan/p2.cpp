#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

int n, s;
int powers[100002];
int targets[100002];
int main() {
	cin >> n >> s;
	set<pii> visited;
	set<int> res;
	for (int i = 1; i <= n; i++) {
		cin >> targets[i];
		cin >> powers[i];
	}

	int power = 1;
	bool reverse = false;
	while (!visited.count({s, power})) {

		// out of line
		if (s <= 0 || s > n) {
			break;
		}
		// cout << "at " << s << " with " << power << endl;
		visited.insert({s, power});

		if (targets[s]) {
			if (abs(power) >= powers[s]) {
				res.insert(s);
			}
		} else {
			power = abs(power) + powers[s];
			reverse = !reverse;
		}

		if (reverse) {
			power = abs(power) * -1;
		} else {
			power = abs(power);
		}
		s += power;
	}

	cout << res.size() << endl;
	return 0;
}