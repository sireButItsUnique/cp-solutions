#include <bits/stdc++.h>
using namespace std;

int main() {
	int p, n, r;
	cin >> p >> n >> r;

	int lastInfect = n;
	int i = 0;
	while (n <= p) {
		i++;
		n += lastInfect * r;
		lastInfect *= r;
	}

	cout << i;
	return 0;
}