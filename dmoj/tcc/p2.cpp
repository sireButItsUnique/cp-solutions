#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;

ll n, k;
vector<ll> nums;
vector<ll> prefix;
vector<vector<int>> pos;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
    cin >> n >> k;
    nums = vector<ll>(n);
    pos = vector<vector<int>>(n + 1);
    prefix = vector<ll>(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        pos[nums[i]].push_back(i);
    }
    prefix[n-1] = nums[n-1];
    for (int i = n-1; i >= 0; i--) {
        prefix[i] = prefix[i+1] + nums[i];
    }

	// return res
	ll res = 0;
    for (int d = 1; d <= k; d++) {
        ll x, last = n;
        cin >> x;
        for (int i = pos[d].size() - 1; i >= 0; i--) {
            int idx = pos[d][i];
            if (nums[idx] == d) {
                if (idx < n-1) {
                    res += max(0ll, prefix[idx+1] - prefix[last]);
                }
                last = min(max(0ll, last - x - 1), max(0ll, idx - x));
            }
        }
        res += max(0ll, prefix[0] - prefix[last]);

        // cout
        cout << fixed << res << endl;
        res = 0;
    }
	return 0;
}