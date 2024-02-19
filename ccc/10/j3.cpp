#include <bits/stdc++.h>
using namespace std;

int main() {
	int cmd;
	int n;
	char var1, var2;
	int a = 0, b = 0;
	while (true) {
		cin >> cmd;
		if (cmd == 7) {
			return 0;
		} else if (cmd == 6) {
			cin >> var1 >> var2;
			if (var1 == 'A') {
				if (var2 == 'A') {
					a = 1;
				} else {
					a = floor(a / b);
				}
			} else {
				if (var2 == 'B') {
					b = 1;
				} else {
					b = floor(b / a);
				}
			}
		} else if (cmd == 5) {
			cin >> var1 >> var2;
			if (var1 == 'A') {
				if (var2 == 'A') {
					a = 0;
				} else {
					a -= b;
				}
			} else {
				if (var2 == 'B') {
					b = 0;
				} else {
					b -= a;
				}
			}
		} else if (cmd == 4) {
			cin >> var1 >> var2;
			if (var1 == 'A') {
				if (var2 == 'A') {
					a *= a;
				} else {
					a *= b;
				}
			} else {
				if (var2 == 'B') {
					b *= b;
				} else {
					b *= a;
				}
			}
		} else if (cmd == 3) {
			cin >> var1 >> var2;
			if (var1 == 'A') {
				if (var2 == 'A') {
					a += a;
				} else {
					a += b;
				}
			} else {
				if (var2 == 'B') {
					b += b;
				} else {
					b += a;
				}
			}
		} else if (cmd == 2) {
			cin >> var1;
			if (var1 == 'A') {
				cout << a << endl;
			} else {
				cout << b << endl;
			}
		} else if (cmd == 1) {
			cin >> var1 >> n;
			if (var1 == 'A') {
				a = n;
				// cout << "A = " << a << endl;
			} else {
				b = n;
				// cout << "B = " << b << endl;
			}
		}
	}
}