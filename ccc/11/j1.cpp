#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cout << "How many antennas?" << endl;
	cin >> a;
	cout << "How many eyes?" << endl;
	cin >> b;
	if (a >= 3 && b <= 4) {
		cout << "TroyMartian\n";
	}
	if (a <= 6 && b >= 2) {
		cout << "VladSaturnian\n";
	}
	if (a <= 2 && b <= 3) {
		cout << "GraemeMercurian\n";
	}
	return 0;
}