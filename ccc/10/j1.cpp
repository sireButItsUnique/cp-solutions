#include <bits/stdc++.h>
using namespace std;

int main() {
	int num;
	cin >> num;
	if (num == 1 || num == 9 || num == 10) {
		cout << 1;
		return 0;
	}
	if (num == 2 || num == 3 || num == 7 || num == 8) {
		cout << 2;
		return 0;
	}
	if (num == 4 || num == 5 || num == 6) {
		cout << 3;
		return 0;
	}
	return 0;
}