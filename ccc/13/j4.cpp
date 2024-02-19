#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

vector<int> tasks;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	int t, c;
	cin >> t >> c;
	tasks.resize(c);
	for (int i = 0; i < c; i++) {
		cin >> tasks[i];
	}
	sort(tasks.begin(), tasks.end());

	// return res
	for (int i = 0; i < c; i++) {
		t -= tasks[i];
		if (t < 0) {
			cout << i;
			return 0;
		}
	}
	cout << tasks.size();
	return 0;
}