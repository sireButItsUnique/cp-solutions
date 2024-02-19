#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	int h = 0;
	string w;
	for (int i = 0; i < n; i++) {
		int buf;
		string bufs;
		cin >> bufs;
		cin >> buf;
		if (buf > h) {
			h = buf;
			w = bufs;
		}
	}
	cout << w;

	return 0;
}