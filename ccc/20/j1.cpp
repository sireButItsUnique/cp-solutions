#include <bits/stdc++.h>
using namespace std;

int main() {
	int s, m, l;
	cin >> s >> m >> l;
	if (s + (m * 2) + (l * 3) >= 10) {
		cout << "happy";
		return 0;
	}
	cout << "sad";
	return 0;
}