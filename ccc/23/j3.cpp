#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

vector<string> ppl;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	int n;
	cin >> n;
	ppl.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> ppl[i];
	}

	// return res
	vector<int> res;
	int high = 0;
	for (int day = 0; day < ppl[0].size(); day++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += (ppl[i][day] == 'Y');
		}
		if (cnt == high) {
			res.push_back(day + 1);
		}
		if (cnt > high) {
			res.clear();
			res.push_back(day + 1);
			high = cnt;
		}
	}

	for (int i = 0; i < res.size() - 1; i++) {
		cout << res[i] << ",";
	}
	cout << res.back();
	return 0;
}