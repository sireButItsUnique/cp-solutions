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

// either move lightest pig to the front or heaviest pig to the back (but before smt thats heavier)
ll n, l;
vector<ll> pigs;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
    cin >> n >> l;
    pigs = vector<ll>(n);
    for (int i = 0; i < n; i++) {
        cin >> pigs[i];
    }

	// return res
	ll res = 0;
    ll weight = 0;
    ll heaviest = 0;
    ll lightest = LLONG_MAX;

    // try without moving
    for (ll i = 0; i <= n; i++) {
        if (i == n) {
            cout << fixed << n << endl;
            return 0;
        }
        heaviest = max(heaviest, pigs[i]);
        weight += pigs[i];
        if (weight > l) {
            res = i;
            break;
        }
    }
    for (ll i = res; i < n; i++) {
        lightest = min(lightest, pigs[i]);
    }

    // move heaviest to the back
    weight = (-1 * heaviest);
    bool broken = false;
    for (ll i = 0; i < n; i++) {
        if (pigs[i] > heaviest) {
            weight += heaviest;
        } else {
            weight += pigs[i];
        }
        if (weight > l) {
            res = max(res, i - 1);
            broken = true;
            break;
        }
        if (pigs[i] > heaviest) {
            res = max(res, i);
            broken = true;
            break;
        }
    }
    if (!broken) {
        res = max(res, n - 1);
    }
    broken = false;
    
    // move lightest to front
    if (lightest <= l) {
        weight = lightest;
        for (ll i = 0; i < n; i++) {
            weight += pigs[i];
            if (weight > l) {
                res = max(res, i + 1);
                break;
            }
        }
    }
	cout << fixed << res << endl;
	return 0;
}