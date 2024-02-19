#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a == 60 && c == 60 && b == 60) {
		cout << "Equilateral";
	} else if (a + b + c == 180) {
		if (a == b || b == c || a == c) {
			cout << "Isosceles";
		} else {
			cout << "Scalene";
		}
	} else {
		cout << "Error";
	}
	return 0;
}