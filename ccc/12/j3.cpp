#include <bits/stdc++.h>
using namespace std;

int main() {
	char pattern[3][3] = {{'*', 'x', '*'}, {' ', 'x', 'x'}, {'*', ' ', '*'}};
	int k;
	cin >> k;
	for (int i = 0; i < k * 3; i++) {
		string row = "";
		int orgRow = floor(i / k);
		for (int j = 0; j < k * 3; j++) {
			int orgCol = floor(j / k);
			row.push_back(pattern[orgRow][orgCol]);
		}
		cout << row << endl;
	}
	return 0;
}