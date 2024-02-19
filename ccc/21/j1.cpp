#include <bits/stdc++.h>
using namespace std;

int main() {
	int B, P;
	cin >> B;

	cout << 5 * B - 400;

	if (B < 100) {
		cout << "\n1";
	} else if (B == 100) {
		cout << "\n0";
	} else {
		cout << "\n-1";
	}

	return 0;
}