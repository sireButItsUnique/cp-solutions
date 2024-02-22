#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;

int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
    cin >> n;

	// return res
	ll res = 0;
    while (n >= 0) {
        if (n % 4 == 0) {
            res++;
        }
        n -= 5;
    }
	cout << fixed << res << endl;
	return 0;
}