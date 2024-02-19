#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	int p, c;
	cin >> p >> c;

	// return res
	ll res = (p * 50 - c * 10) + 500 * (p > c);
	cout << fixed << res;
	return 0;
}