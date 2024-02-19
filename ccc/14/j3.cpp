#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a = 100;
	int b = 100;

	for (int i = 0; i < n; i++) {
		int c, d;
		cin >> c >> d;
		if (c != d) {
			if (c > d) {
				b -= max(c, d);
			} else {
				a -= max(c, d);
			}
		}
	}

	cout << a << endl << b;
	return 0;
}