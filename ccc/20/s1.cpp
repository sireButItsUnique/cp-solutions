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
	vector<pair<double, double>> data(n);
	double res = 0;

	for (int i = 0; i < n; i++) {
		double tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		data[i] = {tmp1, tmp2};
	}
	sort(data.begin(), data.end());

	for (int i = 1; i < n; i++) {
		res = max(res, abs(data[i].second - data[i - 1].second) /
						   abs(data[i].first - data[i - 1].first));
	}

	// return res
	cout << fixed << res;
	return 0;
}