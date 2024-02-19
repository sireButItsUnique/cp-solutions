// build network with kruskals
// if theres a tie, use the one thats alr in the thing
// D != 0 makes it bad -> have to apply D to the most expensive pipe of every network
// therefore if pre D the network's most expensive pipe is less than D, a more expensive network pre D could end up being same cost

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input

	// return res
	ll res;
	cout << fixed << res;
	return 0;
}