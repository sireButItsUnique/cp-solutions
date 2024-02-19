#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int dir = (s[0] - '0') + (s[1] - '0');
	string d;
	int steps = ((s[2] - '0') * 100) + ((s[3] - '0') * 10) + ((s[4] - '0'));

	while (s != "99999") {
		if (dir % 2 && dir != 0) {
			d = "left ";
		} else if (dir != 0) {
			d = "right ";
		}

		cout << d << steps << endl;
		cin >> s;
		dir = (s[0] - '0') + (s[1] - '0');
		steps = ((s[2] - '0') * 100) + ((s[3] - '0') * 10) + ((s[4] - '0'));
	}

	return 0;
}