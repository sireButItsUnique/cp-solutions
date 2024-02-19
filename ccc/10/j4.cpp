#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (true) {
		// messing with input
		cin >> n;
		if (n == 0)
			return 0;
		int temps[n];
		int pattern[n - 1];
		for (int i = 0; i < n; i++) {
			cin >> temps[i];
		}
		// cout << "actual pattern: ";
		for (int i = 0; i < (n - 1); i++) {
			pattern[i] = temps[i + 1] - temps[i];
			// cout << temps[i + 1] - temps[i];
		}
		// cout << endl;

		// calculating
		for (int i = 1; i <= n; i++) {
			// making pattern
			int testPattern[i];
			for (int j = 0; j < i; j++) {
				testPattern[j] = pattern[j];
			}

			// making full array if pattern were to be followed
			int comparePattern[n - 1];
			for (int j = 0; j < n - 1; j++) {
				comparePattern[j] = testPattern[j % i];
			}
			// cout << "pattern " + to_string(i) + ": ";
			for (int j = 0; j < n - 1; j++) {
				// cout << comparePattern[j];
			}
			// cout << endl;

			// if testPattern matches pattern, it works
			bool matches = true;
			for (int j = 0; j < n - 1; j++) {
				// cout << "testing \n";
				// cout << comparePattern[j] - pattern[j];
				if (comparePattern[j] != pattern[j]) {
					matches = false;
				}
			}
			if (n == 1) {
				cout << 0 << endl;
				i = n + 1;
			} else if (matches) {
				cout << i << endl;
				i = n + 1;
			}
		}
	}
}