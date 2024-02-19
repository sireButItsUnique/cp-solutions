#include <bits/stdc++.h>
using namespace std;

int main() {
	int a1, a2, a3, b1, b2, b3;
	cin >> a3 >> a2 >> a1 >> b3 >> b2 >> b1;
	int a = a1 + a2 * 2 + a3 * 3;
	int b = b1 + b2 * 2 + b3 * 3;

	if (a > b) {
		cout << 'A';
	} else {
		if (a == b) {
			cout << 'T';
		} else {
			cout << 'B';
		}
	}

	return 0;
}