#include <bits/stdc++.h>
using namespace std;

int main() {
	int square[4][4], magikNum = 0;

	// cin.ignore(1);
	for (int i = 0; i < 4; i++) {
		string buffer, numBuffer;
		int numNum = 0;
		getline(cin, buffer);
		for (int j = 0; j < buffer.size(); j++) {
			if (buffer.at(j) == ' ') {
				square[i][numNum] = atoi(numBuffer.c_str());
				numBuffer = "";
				numNum++;
			} else {
				numBuffer.push_back(buffer.at(j));
			}
		}
		square[i][numNum] = atoi(numBuffer.c_str());
	}

	for (int j = 0; j < 4; j++) {
		magikNum += square[0][j];
	}

	for (int i = 0; i < 4; i++) {
		int colSum = 0;
		for (int j = 0; j < 4; j++) {
			colSum += square[i][j];
		}
		if (colSum != magikNum) {
			cout << "not magic";
			return 0;
		}
	}

	for (int i = 0; i < 4; i++) {
		int rowSum = 0;
		for (int j = 0; j < 4; j++) {
			rowSum += square[j][i];
		}
		if (rowSum != magikNum) {
			cout << "not magic";
			return 0;
		}
	}

	cout << "magic";
	return 0;
}