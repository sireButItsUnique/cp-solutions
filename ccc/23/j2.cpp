#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	map<string, int> m;
	m["Poblano"] = 1500;
	m["Mirasol"] = 6000;
	m["Serrano"] = 15500;
	m["Cayenne"] = 40000;
	m["Thai"] = 75000;
	m["Habanero"] = 125000;

	// return res
	ll res = 0;
	int n;
	cin >> n;
	while (n--) {
		string tmp;
		cin >> tmp;
		res += m[tmp];
	}
	cout << res;
	return 0;
}