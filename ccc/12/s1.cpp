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

int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	cin >> n;

	// return res
	ll res = 0;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			res += n - j - 1;
		}
	}
	cout << fixed << res;
	return 0;
}