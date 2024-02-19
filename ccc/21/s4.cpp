#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

// no point in getting on train once left (wait = same pace as js staying on
// train) if choose to get off there must exist a path from walkway to end if
// its less than how long it takes by train we should get off and take it

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	int n, w, d;
	cin >> n >> w >> d;
	vector<vector<int>> adj(n + 1, vector<int>());
	vector<int> stations(n);
	map<int, int> whereInArr;
	while (w--) {
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		cin >> stations[i];
		whereInArr[stations[i]] = i;
	}

	// bfs from ending walkway
	map<int, int> dist; // dist[station] = distFromEnd;
	queue<pii> bfs;		// bfs[i] = {station, distFromEnd};
	bfs.push({n, 0});
	dist[n] = 0;

	while (!bfs.empty()) {
		int station = bfs.front().first;
		int distFromEnd = bfs.front().second;

		for (int i = 0; i < adj[station].size(); i++) {
			int dest = adj[station][i];
			if (dist.find(dest) == dist.end()) {
				bfs.push({dest, distFromEnd + 1});
				dist[dest] = distFromEnd + 1;
			}
		}
		bfs.pop();
	}

	// search for every day
	multiset<int> res;
	for (auto &i : dist) {
		res.insert(whereInArr[i.first] + i.second);
	}

	while (d--) {
		int x, y;
		cin >> x >> y;

		int stationX = stations[x - 1], stationY = stations[y - 1];
		if (dist.count(stationX)) {
			res.erase(res.find(whereInArr[stationX] + dist[stationX]));
		}
		if (dist.count(stationY)) {
			res.erase(res.find(whereInArr[stationY] + dist[stationY]));
		}

		swap(stations[x - 1], stations[y - 1]);
		swap(whereInArr[stations[x - 1]], whereInArr[stations[y - 1]]);
		if (dist.count(stationX)) {
			res.insert(whereInArr[stationX] + dist[stationX]);
		}
		if (dist.count(stationY)) {
			res.insert(whereInArr[stationY] + dist[stationY]);
		}

		int r = *(res.begin());
		cout << r << "\n";
	}
	return 0;
}