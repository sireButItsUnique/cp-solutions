#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;

ll n, m;
vector<vector<int>> ingredients; // ingredients[i] = {need, cur, smallSize, smallPrice, largeSize, largePrice}

ll calc(ll goal) {
	ll cost = 0;

	// cycle thru ingredients
	for (int i = 0; i < n; i++) {
		ll need = (ingredients[i][0] * goal) - ingredients[i][1];
		ll smallSize = ingredients[i][2];
		ll smallPrice = ingredients[i][3];
		ll largeSize = ingredients[i][4];
		ll largePrice = ingredients[i][5];

		// try buy enough for [goal] meals using all combos
		ll ingredientCost = LLONG_MAX;
		ll numLarge = 0;
		while (need > 0) {
			ll numSmall = ceil(need / (float)smallSize);
			ingredientCost = min(ingredientCost, numLarge * largePrice + numSmall * smallPrice);

			need -= largeSize;
			numLarge++;
		}
		ingredientCost = min(ingredientCost, numLarge * largePrice);
		cost += ingredientCost;
	}
	return cost;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	cin >> n >> m;
	ingredients = vector<vector<int>>(n + 1, vector<int>(6));
	for (int i = 0; i < n; i++) {
		cin >> ingredients[i][0] >> ingredients[i][1] >> ingredients[i][2];
		cin >> ingredients[i][3] >> ingredients[i][4] >> ingredients[i][5];
	}

	// bin search
	ll lower = 0, upper = 50000;
	while (lower < upper) {

		// cycle thru each ingredient
		ll goal = (lower + upper) >> 1;
		ll cost = calc(goal);

		if (cost <= m) {
			lower = goal + 1;
		} else {
			upper = goal;
		}
	}

	if (calc(lower) > m) {
		lower--;
	}
	cout << fixed << lower << endl;
	return 0;
}