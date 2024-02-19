#include <bits/stdc++.h>
using namespace std;
/*
- - - - -
* - * - -
- - - - -
- - - - -
*/
int main() {
	int startX, startY, endX, endY, totalCharge;
	string buffer;

	cin >> startX >> startY >> endX >> endY;
	// getline(cin, buffer);
	// startX = buffer.at(0) - '0';
	// startY = buffer.at(2) - '0';

	// getline(cin, buffer);
	// endX = buffer.at(0) - '0';
	// endY = buffer.at(2) - '0';

	cin >> totalCharge;

	int x = abs(endX - startX);
	int y = abs(endY - startY);
	int dist = x + y;

	if (totalCharge >= dist) {
		if (((totalCharge - dist) % 2) == 0) {
			cout << 'Y';
			return 0;
		}
	}
	cout << 'N';
	return 0;
}