#include <bits/stdc++.h>
using namespace std;

void getSize(string s, int &xMin, int &yMin, int &xMax, int &yMax) {
	stringstream ss(s);
	string num;
	int i = 0;
	while (!ss.eof()) {
		getline(ss, num, ',');
		int NUM = stoi(num);
		if (i == 0) {
			xMin = min(NUM, xMin);
			xMax = max(NUM, xMax);
		} else {
			yMin = min(NUM, yMin);
			yMax = max(NUM, yMax);
		}
		i++;
	}
	return;
}

int main() {
	int n;
	cin >> n;

	int xMin = 101;
	int yMin = 101;
	int xMax = 0;
	int yMax = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		getSize(s, xMin, yMin, xMax, yMax);
	}

	cout << xMin - 1 << ',' << yMin - 1 << endl << xMax + 1 << ',' << yMax + 1;
	return 0;
}