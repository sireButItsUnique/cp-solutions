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
	ll res = 0;
	for (int i = 0; i < n; i++) {
		cin >> grass[i];
	}

	double net = 0;
	for (int i = 0; i < n; i++) {

		for (int j = i + 1; j < n; j++) {
			grass[j] += (-1 * grass[i] * (j - i + 1));
		}
		res += abs(grass[i]);
	}

	cout << res << endl;
	return 0;
}