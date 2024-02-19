#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	int n;
	cin >> n;
	vector<double> villages(n);
	for (int i = 0; i < n; i++) {
		cin >> villages[i];
	}
	sort(villages.begin(), villages.end());

	// return res
	double res = numeric_limits<double>::infinity();
	for (int i = 1; i < n - 1; i++) {
		res = min(res, (villages[i] - villages[i - 1]) / 2 + (villages[i + 1] - villages[i]) / 2);
	}
	cout << fixed << setprecision(1) << res;
	return 0;
}