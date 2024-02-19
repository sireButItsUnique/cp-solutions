#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

double n;
ll grass[100001];

/*
1 3 -2 -7 5
+1 +3 -2 -7 +5
pwr = -5 * 1

0 +1 -5 -11 0
pwr = -4 * 1

0 0 -7 -14 -4
pwr = 3 * 7

0 0  0 0  17
pwr = 1 * 17

*/
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> grass[i];
	}

	ll res = abs(grass[0]);
	ll net = (-1 * grass[0]);
	for (int i = 1; i < n; i++) {
		ll afterSpray = grass[i] - grass[i - 1] + net;
		res += abs(afterSpray);
		net -= afterSpray;
	}

	cout << res << endl;
	return 0;
}