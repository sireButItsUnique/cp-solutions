#include <bits/stdc++.h>
using namespace std;

int main() {
	char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
						 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
						 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char cons[21] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n',
					 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
	string code, translation;
	cin >> code;

	for (int i = 0; i < code.size(); i++) {
		if (code.at(i) == 'a' || code.at(i) == 'e' || code.at(i) == 'i' ||
			code.at(i) == 'o' || code.at(i) == 'u') {
			translation.push_back(code.at(i));
		} else {
			translation.push_back(code.at(i));
			// finding letter pos
			for (int findInArray = 0; findInArray < 26; findInArray++) {
				if (code.at(i) == alphabet[findInArray]) {

					// finding vowels
					for (int findVowel = 1; findVowel < 26; findVowel++) {
						if (!(findVowel + findInArray > 25 ||
							  findInArray - findVowel < 0)) {

							// finding vowel ahead of it
							char letter = alphabet[findInArray - findVowel];
							char letterb = alphabet[findInArray + findVowel];
							if (letter == 'a' || letter == 'e' ||
								letter == 'i' || letter == 'o' ||
								letter == 'u') {
								translation.push_back(letter);
								letterb = 'n';
								findVowel = 27;
							}

							// finding  vowel behind it
							if (letterb == 'a' || letterb == 'e' ||
								letterb == 'i' || letterb == 'o' ||
								letterb == 'u') {
								translation.push_back(letterb);
								findVowel = 27;
							}
						} else if (findVowel + findInArray < 26) {
							char letterb = alphabet[findInArray + findVowel];
							if (letterb == 'a' || letterb == 'e' ||
								letterb == 'i' || letterb == 'o' ||
								letterb == 'u') {
								translation.push_back(letterb);
								findVowel = 27;
							}
						} else if (findInArray - findVowel >= 0) {
							char letter = alphabet[findInArray - findVowel];
							if (letter == 'a' || letter == 'e' ||
								letter == 'i' || letter == 'o' ||
								letter == 'u') {
								translation.push_back(letter);
								findVowel = 27;
							}
						}
					}

					// finding consonant
					if (code.at(i) == 'z') {
						translation.push_back('z');
					} else {
						for (int findVowel = 1; findVowel < 26; findVowel++) {
							if (!(findVowel + findInArray > 25)) {

								// finding const ahead of it
								char letter = alphabet[findInArray + findVowel];
								if (!(letter == 'a' || letter == 'e' ||
									  letter == 'i' || letter == 'o' ||
									  letter == 'u')) {
									translation.push_back(letter);
									findVowel = 27;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << translation;
	return 0;
}