#include <bits/stdc++.h>
using namespace std;

int main() {
	int depth[4];
	for (int i = 0; i < 4; i++) {
		cin >> depth[i];
	}

	bool rise = true;
	for (int i = 0; i < 3; i++) {
		if (depth[i + 1] <= depth[i]) {
			rise = false;
		}
	}

	bool fall = true;
	for (int i = 0; i < 3; i++) {
		if (depth[i + 1] >= depth[i]) {
			fall = false;
		}
	}

	bool cons = true;
	for (int i = 1; i < 4; i++) {
		if (depth[0] != depth[i]) {
			cons = false;
		}
	}

	if (rise) {
		cout << "Fish Rising";
		return 0;
	}
	if (fall) {
		cout << "Fish Diving";
		return 0;
	}
	if (cons) {
		cout << "Fish At Constant Depth";
		return 0;
	}
	cout << "No Fish";
}