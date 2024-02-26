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

string s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	cin >> s;

	// return res
	ll res = 0;
	ll ptr1 = 0;
	for (int ptr2 = 0; ptr2 < s.size(); ptr2++) {
		if (s[ptr2] != s[ptr1]) {
			res = max(res, ptr2 - ptr1);
			ptr1 = ptr2;
		}
	}
	res = max(res, (ll)s.size() - ptr1);
	cout << fixed << res << endl;
	return 0;
}