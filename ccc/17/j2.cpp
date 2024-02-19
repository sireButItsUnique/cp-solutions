#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, k, total;
	total = 0;
	cin >> N;
	cin >> k;

	for (int i = 0; i <= k; i++) {
		total += N * pow(10, i);
	}

	cout << total;
}