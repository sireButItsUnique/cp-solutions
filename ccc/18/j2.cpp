#include <bits/stdc++.h>
using namespace std;

int main() {
	int u;
	string a, b;
	cin >> u >> a >> b;

	int res = 0;
	for (int i = 0; i < u; i++) {
		if (a[i] == 'C' && b[i] == 'C') {
			res++;
		}
	}
	cout << res;
	return 0;
}