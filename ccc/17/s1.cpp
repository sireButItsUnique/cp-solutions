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
vector<int> a(100001), b(100001);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	// return res
	ll res = 0;
	int as = 0, bs = 0;
	for (int i = 0; i < n; i++) {
		as += a[i];
		bs += b[i];
		if (as == bs) {
			res = i + 1;
		}
	}
	cout << fixed << res;
	return 0;
}