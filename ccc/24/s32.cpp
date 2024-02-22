#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;

/*
swipe from both edges
*/
ll n;
vector<ll> a, b;
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

    // return res -> res = {swipeRight, start, end}
    ll left = 0;
    ll right = n - 1;
    while (a != b) {
        
        // cout << left << "..." << right << endl;
        // for (int i = 0; i < n; i++) {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        // converged
        if (left == right) {
            if (b[left - 1] == b[left]) {
                res.push({1, left - 1, left});
                a[left] = b[left];
                break;
            }
            if (b[right + 1] == b[right]) {
                res.push({0, right + 1, right});
                a[right] = b[right];
                break;
            }
        }

        // do the leftmost one
        if (a[left] != b[left]) {

            // swipe from the left (to right)
            if ((left != 0) && (b[left-1] == b[left])) {
                res.push({1, left - 1, left});
                a[left] = b[left];
            }

            // swipe from the right (to left)
            else {
                bool found = false;
                for (int j = left + 1; j <= right; j++) {
                    if (a[j] == b[left]) {
                        res.push({0, j, left});
                        found = true;
                        a[left] = b[left];
                        break;
                    }
                    a[j] = b[left];
                }
                if (!found) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
        left++;
        if (a == b) {
            break;
        }

        // do the rightmost one
        if (a[right] != b[right]) {

            // swipe from the right (to left)
            if ((right != n-1) && (b[right+1] == b[right])) {
                res.push({0, right + 1, right});
                a[right] = b[right];
            }

            // swipe from the left (to right)
            else {
                bool found = false;
                for (int j = right - 1; j >= left - 1; j--) {
                    if (a[j] == b[right]) {
                        res.push({1, j, right});
                        found = true;
                        a[right] = b[right];
                        break;
                    }
                    a[j] = b[right];
                }
                if (!found) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
        right--;
    }


    cout << "YES" << endl;
    print();
	return 0;
}