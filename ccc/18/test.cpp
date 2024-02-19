#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;

ll res = 0;
ll n, m, p, q;
vector<vector<pii>> flights;
vector<vector<pii>> portals;
vector<pair<ll, pii>> edges;
vector<ll> parent;

int findParent(int node) {
	if (parent[node] == node)
		return node;
	return parent[node] = findParent(parent[node]);
}

void kruskal() {
	sort(edges.begin(), edges.end());
	for (int i = 0; i <= m + n; ++i)
		parent[i] = i;

	for (auto edge : edges) {
		int u = edge.second.first, v = edge.second.second;
		int pu = findParent(u), pv = findParent(v);
		if (pu != pv) {
			parent[pu] = pv;
			res += edge.first;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	cin >> n >> m >> p >> q;
	flights.resize(n + 1, {});
	portals.resize(m + 1, {}); // Corrected size to m + 1

	ll org = 0; // Initialize org value

	for (int i = 0; i < p; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		org += c * n; // Multiply flight energy cost by the number of cities
		flights[a].push_back({c, b});
		flights[b].push_back({c, a});
		edges.push_back({c, {a, b}});
	}
	for (int i = 0; i < q; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		org += z * m; // Multiply portal energy cost by the number of planets
		portals[x].push_back({z, y});
		portals[y].push_back({z, x});
		edges.push_back({z, {x, y}});
	}

	// Initialize the parent array for disjoint set
	parent.resize(m + n + 1);

	// calculate minimum spanning tree using Kruskal's algorithm
	kruskal();

	// return result
	cout << fixed << (org - res);
	return 0;
}
