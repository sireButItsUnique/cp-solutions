#include <bits/stdc++.h>
using namespace std;
int main() {
	int a = 0, b = 0;
	int f1, f2, b1, b2;
	cin >> f1 >> b1 >> f2 >> b2;
	int steps;
	cin >> steps;
	for (int i = 0; i < steps; i++) {
		if ((i % (f1 + b1)) < f1) {
			a += 1;
		} else {
			a -= 1;
		}
		if ((i % (f2 + b2)) < f2) {
			b += 1;
		} else {
			b -= 1;
		}
	}
	if (b == a) {
		cout << "Tied";
		return 0;
	}
	if (b > a) {
		cout << "Byron";
		return 0;
	}
	cout << "Nikky";
	return 0;
}