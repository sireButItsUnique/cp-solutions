#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

vector<int> row1, row2;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	int c;
	int triangles = 0, collisions = 0;
	cin >> c;
	row1.resize(c);
	row2.resize(c);
	for (int i = 0; i < c; i++) {
		cin >> row1[i];
		triangles += row1[i];
	}
	for (int i = 0; i < c; i++) {
		cin >> row2[i];
		triangles += row2[i];
	}

	for (int i = 1; i < c; i++) {
		collisions += (row1[i] && row1[i - 1]);
		collisions += (row2[i] && row2[i - 1]);
	}
	for (int i = 0; i < c; i += 2) {
		collisions += (row1[i] && row2[i]);
	}

	// return res
	ll res = (triangles * 3) - (collisions * 2);
	cout << fixed << res;
	return 0;
}