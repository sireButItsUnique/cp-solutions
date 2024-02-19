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

ll n;
map<ll, ll> cnt;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		cnt[tmp]++;
	}
	vector<pii> sensors; // sensors[i] = {freq, reading}
	for (auto &m : cnt) {
		sensors.push_back({m.second, m.first});
	}
	sort(sensors.rbegin(), sensors.rend());

	// return res
	ll res;
	ll high = INT_MIN, low = INT_MAX;
	for (int i = (sensors[0].first != sensors[1].first); i < sensors.size(); i++) {
		if (sensors[i].first != sensors[(sensors[0].first != sensors[1].first)].first) {
			break;
		}
		high = max(high, sensors[i].second);
		low = min(low, sensors[i].second);
	}

	res = abs(sensors[0].second - high);
	res = max(res, abs(sensors[0].second - low));
	if (sensors[0].first == sensors[1].first) {
		res = high - low;
	}
	cout << fixed << res;
	return 0;
}