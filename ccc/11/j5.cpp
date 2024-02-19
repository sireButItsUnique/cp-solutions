#include <bits/stdc++.h>
using namespace std;

int main() {
	// input
	int n;
	cin >> n;
	int people[n];
	for (int i = 0; i < n; i++) {
		people[i] = 1;
	}

	// multiply each person by # of ppl theyve invited
	// keep multipling the way up
	for (int i = 0; i < n - 1; i++) {
		int inviter;
		cin >> inviter;
		inviter--;

		people[inviter] *= (people[i] + 1);
	}

	cout << people[n - 1];
	return 0;
}