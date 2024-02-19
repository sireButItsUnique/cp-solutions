#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

// for each k it always goes dp[5] dp[4] dp[4] dp[4] dp[3] dp[3] etc etc
// no need to do all that -> calc how long the thing will last for

/*
i % k = rem
# = rem / (i / k)
i = 15
2 - 7
3 - 5
4 - 3
5 - 3
6 - 2
7 - 2
8 - 1
9 - 1
10 - 1
11 - 1
12 - 1
13 - 1
14 - 1
15 - 1
*/
unordered_map<int, ll> dp;
int n;

ll rec(int i) {

	ll cnt;
	for (int k = 2; k <= i; k += cnt) {
		cnt = ((i % k) / (i / k)) + 1;
		if (!dp[i / k]) {
			rec(i / k);
		}
		dp[i] += cnt * dp[i / k];
	}
	return dp[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	cin >> n;
	dp[1] = 1;
	dp[2] = 1;

	// return res
	if (!dp[n]) {
		rec(n);
	}
	cout << fixed << dp[n];
	return 0;
}