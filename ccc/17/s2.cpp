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
vector<int> waves;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	cin >> n;
	waves.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> waves[i];
	}
	sort(waves.begin(), waves.end());

	// n = 8, split = 3
	// n = 5, split = 2
	// return res
	vector<int> res(n);
	int ptr1 = ceil(n / 2.0) - 1, ptr2 = ceil(n / 2.0);
	for (int i = 0; i <= ptr1; i++) {
		res[i * 2] = waves[ptr1 - i];
	}
	for (int i = ptr2; i < n; i++) {
		res[(i - ptr2) * 2 + 1] = waves[i];
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	return 0;
}