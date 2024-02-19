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

map<char, int> m;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	m['I'] = 1;
	m['V'] = 5;
	m['X'] = 10;
	m['L'] = 50;
	m['C'] = 100;
	m['D'] = 500;
	m['M'] = 1000;
	cin >> s;

	// return res
	ll prev = (s[0] - '0') * m[s[1]];
	ll res = prev;
	for (int i = 2; i < s.size(); i += 2) {
		if (m[s[i + 1]] > m[s[i - 1]]) {
			res -= 2 * prev;
		}
		prev = (s[i] - '0') * m[s[i + 1]];
		res += prev;
	}
	cout << fixed << res;
	return 0;
}