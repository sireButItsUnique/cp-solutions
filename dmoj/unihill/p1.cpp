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

int x, y, z, l;
int plr1 = 0, plr2 = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
    cin >> x >> y >> z >> l;

	// return res
	ll res;
    while (plr1 < l && plr2 < l) {
        if (plr1 < plr2) {
            plr1 += x;
        } else {
            plr2 += y;
            if (plr2 >= l) {
                break;
            }
            plr1 += z;
        }
    }
    if (plr1 >= l) {
        res = 1;
    } else {
        res = 2;
    }
	cout << fixed << res << endl;
	return 0;
}