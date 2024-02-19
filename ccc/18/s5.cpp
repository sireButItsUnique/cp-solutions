#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;

class Dsu {
public:
	vector<ll> parent;

	Dsu(int n) {
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

ll org = 0;
ll res = 0;
ll n, m, p, q;
priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;

// planet/city forms grid system -> instead connect all rows and cols
// issue is we gotta use kruskal with a dsu

// pq[i] = {cost, planet, city, isPlanet}
void kruskal() {

	// init
	ll numCities = m;
	ll numPlanets = n;
	Dsu cities(numCities + 1);
	Dsu planets(numPlanets + 1);

	// run
	while (numCities > 1 || numPlanets > 1) {

		// lazily skip
		int a = pq.top()[1];
		int b = pq.top()[2];
		bool isPlanet = pq.top()[3];
		while (isPlanet ? (planets.get(a) == planets.get(b)) : (cities.get(a) == cities.get(b))) {
			// cout << "popped " << (pq.top()[3] ? "planets " : "cities ") << a << " to " << b << endl;
			pq.pop();
			a = pq.top()[1];
			b = pq.top()[2];
			isPlanet = pq.top()[3];
		}

		// include node
		if (isPlanet) {
			// cout << "joined planets " << a << " and " << b << " for " << (pq.top()[0] * numCities) << endl;
			res += pq.top()[0] * numCities;
			numPlanets--;
			planets.join(a, b);
			pq.pop();
		} else {
			// cout << "joined cities " << a << " and " << b << " for " << (pq.top()[0] * numPlanets) << endl;
			res += pq.top()[0] * numPlanets;
			numCities--;
			cities.join(a, b);
			pq.pop();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	cin >> n >> m >> p >> q;
	for (int i = 0; i < p; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		org += c * n;
		pq.push({c, a, b, false});
	}
	for (int i = 0; i < q; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		org += z * m;
		pq.push({z, x, y, true});
	}

	// calc
	kruskal();

	// return res
	std::cout << fixed << (org - res);
	return 0;
}