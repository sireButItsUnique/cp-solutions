#include <bits/stdc++.h>
using namespace std;

int main() {
	int win[6], total = 0;
	for (int i = 0; i < 6; i++) {
		char buffer;
		cin >> buffer;
		if (buffer == 'W') {
			win[i] = 1;
		} else {
			win[i] = 0;
		}
	}

	for (int i = 0; i < 6; i++) {
		total += win[i];
	}

	if (total >= 5) {
		cout << 1;
	} else if (total >= 3) {
		cout << 2;
	} else if (total >= 1) {
		cout << 3;
	} else {
		cout << -1;
	}
	return 0;
}