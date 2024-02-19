#include <bits/stdc++.h>
using namespace std;

int rec(int slices, int people, int eaten, unordered_map<int, int> &dp) {
	int dpKey = (1000000 * slices) + (1000 * people) + (eaten);
	// dp case
	if (dp.find(dpKey) != dp.end()) {
		return dp[dpKey];
	}

	// base case (nobody left/all pie gone)
	if (people == 2) {
		return 1;
	}

	// visit children
	int eats = eaten;
	int res = 0;
	while (slices >=
		   (people - 1) * eats) { // enough slices for everyone to have the same
		res += rec(slices - eats, people - 1, eats, dp);
		eats++;
	}
	dp[dpKey] = res;
	return res;
}

int main() {
	// input
	int n, k;
	cin >> n >> k;

	// edge cases
	if (k == 1 || n == k) {
		cout << 1;
		return 0;
	}

	// start recursion
	int res = 0;
	int eats = 1;
	unordered_map<int, int> dp;
	while (n >= (k)*eats) {
		res += rec(n - eats, k, eats, dp);
		eats++;
	}
	cout << res;
	return 0;
}