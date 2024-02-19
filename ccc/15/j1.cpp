#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, d;
	cin >> m >> d;

	if (m == 2) {
		if (d == 18) {
			cout << "Special";
		} else if (d > 18) {
			cout << "After";
		} else if (d < 18) {
			cout << "Before";
		}
	} else if (m > 2) {
		cout << "After";
	} else if (m < 2) {
		cout << "Before";
	}
	return 0;
}