#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int i = 2;
	while (true) {
		int c = a - b;
		if (c < 0) {
			cout << i;
			return 0;
		} else if (b < c) {
			i++;
			cout << i;
			return 0;
		}
		a = b;
		b = c;
		i++;
	}
	return 0;
}