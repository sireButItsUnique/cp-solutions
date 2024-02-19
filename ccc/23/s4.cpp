#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

unsigned long long dijkstra(int from, int to, vector<vector<pii>> &adj) {
	vector<ll> dist(2001, LLONG_MAX);
	vector<bool> visited(2001, false);

	dist[from] = 0;
	priority_queue<pair<long long, int>> q;
	q.push({0, from});
	while (!q.empty()) {
		int cur = q.top().second;
		q.pop();
		if (visited[cur])
			continue;
		visited[cur] = true;

		if (cur == to)
			return dist[to];
		for (auto &neighbour : adj[cur]) {
			if (dist[cur] + neighbour.second < dist[neighbour.first]) {
				dist[neighbour.first] = dist[cur] + neighbour.second;
				q.push({-dist[neighbour.first], neighbour.first});
			}
		}
	}
	return dist[to];
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<tuple<int, int, int, int>> edges(m);
	vector<vector<pii>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, l, c;
		cin >> u >> v >> l >> c;
		edges.push_back({l, c, u, v});
	}
	sort(edges.begin(), edges.end());

	unsigned ll res = 0;
	for (auto edge : edges) {
		int dist = get<0>(edge);
		int cost = get<1>(edge);
		int from = get<2>(edge);
		int to = get<3>(edge);
		if (dist < dijkstra(from, to, adj)) {
			adj[from].push_back({to, dist});
			adj[to].push_back({from, dist});
			res += cost;
		}
	}
	cout << res << endl;
	return 0;
}