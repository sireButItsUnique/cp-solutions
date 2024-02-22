#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;

ll t, n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
    cin >> t >> n;

	// return res
    for (int idx = 0; idx < t; idx++) {
        string s, res = "T";
        vector<int> heavy(26, 0);
        cin >> s;
        for (int i = 0; i < n; i++) {
            heavy[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            heavy[i] = max(0, heavy[i] - 1);
        }

        bool shouldBeHeavy = !heavy[s[0] - 'a'];
        for (int i = 1; i < n; i++) {
            if (shouldBeHeavy) {
                if (!heavy[s[i] - 'a']) {
                    res = "F";
                    break;
                }
            } else {
                if (heavy[s[i] - 'a']) {
                    res = "F";
                    break;
                }
            }
            shouldBeHeavy = !shouldBeHeavy;
        }
	    cout << fixed << res << endl;
    }
	return 0;
}