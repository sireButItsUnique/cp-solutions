#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;

ll n;
vector<int> hats;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
    cin >> n;
    hats = vector<int>(n+1);
    for (int i = 0; i < n; i++) {
        cin >> hats[i];
    }

	// return res
	ll res = 0;
    for (int i = 0; i < n / 2; i++) {
        res += 2 * (hats[i] == hats[i + (n / 2)]);
    }
	cout << fixed << res << endl;
	return 0;
}