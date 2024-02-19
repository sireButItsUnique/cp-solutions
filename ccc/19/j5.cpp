#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;

vector<pair<string, string>> rules(3);
int s;
string i, f;
vector<set<string>> dp;
stack<pii> res;

bool rec(int itr, string s) {

	// base case
	if (!itr) {
		if (s == f) {
			return true;
		}
		return false;
	}

	// dp case
	if (dp[itr].count(s)) {
		return false;
	}
	dp[itr].insert(s);

	// keep recing
	for (int i = 0; i < 3; i++) {
		int pos = 0;
		while ((pos = s.find(rules[i].first, pos)) != string::npos) {
			string ns = s;
			ns.replace(pos, rules[i].first.size(), rules[i].second);
			if (rec(itr - 1, ns)) {
				res.push({i + 1, pos + 1});
				return true;
			}
			pos++;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	cin >> rules[0].first >> rules[0].second;
	cin >> rules[1].first >> rules[1].second;
	cin >> rules[2].first >> rules[2].second;
	cin >> s >> i >> f;
	dp.resize(s + 1);

	// return res
	rec(s, i);
	while (res.size()) {
		cout << res.top().first << " ";
		cout << res.top().second << " ";
		i.replace(res.top().second - 1, rules[res.top().first - 1].first.size(), rules[res.top().first - 1].second);
		cout << i << endl;
		res.pop();
	}
	return 0;
}