#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;

/*
swipe from the right only UNLESS the one beside works or it would have worked (i.e. does not destroy work)
*/
ll n;
vector<ll> a, b, acpy, bcpy;
queue<vector<ll>> res;
void print() {
    cout << res.size() << endl;
    while (res.size()) {
        if (res.front()[0]) {
            cout << "R ";
        } else {
            cout << "L ";
        }
        cout << res.front()[1] << " " << res.front()[2] << endl;
        res.pop();
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
    cin >> n;
    a = vector<ll>(n);
    b = vector<ll>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    if (a == b) {
        cout << "YES\n0";
        return 0;
    }
    acpy = a;

    // hardcode
    if (n <= 2) {
        if (a[0] == b[0] && a[0] == b[1]) {
            cout << "YES" << endl << "1" << endl << "R 0 1" << endl;
        } else if (a[1] == b[1] && a[1] == b[0]) {
            cout << "YES" << endl << "1" << endl << "L 1 0" << endl;
        } else {
            cout << "NO" << endl;
        }
        return 0;
    }

    // return res
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {

            // swipe from the left
            if ((i != 0) && (a[i-1] == b[i])) {
                res.push({1, i - 1, i});
                a[i] = b[i];
                continue;
            }
            if ((i != 0) && (b[i-1] == b[i])) {
                res.push({1, i - 1, i});
                a[i] = b[i];
                continue;
            }

            // swipe from the right
            else {
                bool found = false;
                for (int j = i + 1; j < n; j++) {
                    if (a[j] == b[i]) {
                        res.push({0, j, i});
                        found = true;
                        a[i] = b[i];
                        break;
                    }
                    a[j] = b[i];
                }
                if (!found) {
                    break;
                }
            }
        }
        if (i == n-1) {
            cout << "YES" << endl;
            //print();
            return 0;
        }
    }
    res = queue<vector<ll>>();
    for (int i = n-1; i >= 0; i--) {
        if (acpy[i] != b[i]) {

            // swipe from the left
            if ((i != n-1) && (acpy[i+1] == b[i])) {
                res.push({0, i + 1, i});
                acpy[i] = b[i];
                continue;
            }
            if ((i != n-1) && (acpy[i+1] == b[i])) {
                res.push({0, i + 1, i});
                acpy[i] = b[i];
                continue;
            }

            // swipe from the right
            else {
                bool found = false;
                for (int j = i - 1; j >= 0; j--) {
                    if (acpy[j] == b[i]) {
                        found = true;
                        acpy[i] = b[i];
                        res.push({1, j, i});
                        break;
                    }
                    acpy[j] = b[i];
                }
                if (!found) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "YES" << endl;
    //print();
	return 0;
}