#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;

ll n, m;
vector<vector<ll>> points;
vector<vector<ll>> dp;
vector<ll> cnt;

ll factorial(ll start, ll end) {
    ll res = 1;
    for (int i = start; i <= end; i++) {
        res *= i;
    }
    return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
    cout << "♟️" << endl;
    cin >> n >> m;
    points = vector<vector<ll>>(n, vector<ll>(m));
    dp = vector<vector<ll>>(n+1, vector<ll>(n+1, 0));
    cnt = vector<ll>(m + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> points[i][j];
            for (int k = 0; k < i; k++) {
                if (points[i][j] != points[k][j]) {
                    cnt[dp[k][i]]--;
                    dp[k][i]++;
                    cnt[dp[k][i]]++;
                }
            }
        }
    }

	// return res w/ smart brute force
	ll res = 0;
    for (int i = 1; i <= m; i++) {
        if (cnt[i] >= 3) {
            res += ((cnt[i]) * (cnt[i] - 1) * (cnt[i] - 2) / 6);
        }
    }
	cout << fixed << res << endl;
	return 0;
}