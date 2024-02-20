#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;

class Dsu {
public:
	vector<ll> parent;

	Dsu(int n) {
		n += 2;
		parent.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	int get(int node) {
		if (parent[node] != node) {
			parent[node] = get(parent[node]);
		}
		return parent[node];
	}

	void join(int node1, int node2) {
		int group = get(node1);
		parent[group] = node2;
	}
};

// find avg of x then avg of y, two points will be the floor() and ceil()/floor() + 1
ll n;
ll ax, bx, ay, by;
vector<ll> x;
vector<ll> y;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
    cin >> n;
    x = vector<ll>(n);
    y = vector<ll>(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    // odd -> issues
    if (n % 2) {
        ax = x[n/2];
        bx = x[n/2] + 1;
        ay = y[n/2];
        by = y[n/2]; 
    }

    // even -> js choose
    else {
        ax = x[n/2];
        bx = x[n/2] - 1;
        ay = y[n/2];
        by = y[n/2] - 1;
    }

	// return res
	ll res = 0;
    for (int i = 0; i < n; i++) {
        res += abs(ax - x[i]);
        res += abs(bx - x[i]);
        res += abs(ay - y[i]);
        res += abs(by - y[i]);
    }
	cout << fixed << res << endl;
	return 0;
}