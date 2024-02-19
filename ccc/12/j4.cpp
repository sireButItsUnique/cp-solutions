#include <bits/stdc++.h>
using namespace std;

int charToInt(char character) {
	char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
						 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
						 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] == character) {
			return i;
		}
	}
	return -1;
}

// b, 4 -> 1(3) + 4 = 7 -> 9 = i
// i, 4 -> 19 -> letter
// letter, bias -> decode = letter + (letter * pos )
int main() {
	char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
						 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
						 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

	int bias;
	cin >> bias;
	string msg;
	cin >> msg;

	string code = "";
	for (int i = 0; i < msg.size(); i++) {
		int letter = charToInt(msg.at(i)) /* + 1*/;
		int shift = i + 1;
		shift *= 3;
		shift += bias;

		for (int j = 0; j < 26; j++) {
			if (alphabet[(j + shift) % 26] == msg.at(i)) {
				code.push_back(alphabet[j]);
				j = 27;
			}
		}
	}
	cout << code;
	return 0;
}