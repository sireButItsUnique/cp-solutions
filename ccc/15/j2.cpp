#include <bits/stdc++.h>
using namespace std;

int main() {
	string code;
	getline(cin, code);
	int happy = 0, sad = 0;

	for (int i = 0; i < code.size(); i++) {
		if (code.at(i) == ':' && code.at(i + 1) == '-') {
			if (code.at(i + 2) == ')') {
				happy++;
			} else if (code.at(i + 2) == '(') {
				sad++;
			}
		}
	}

	if (happy == 0 && sad == 0) {
		cout << "none";
	} else if (happy == sad) {
		cout << "unsure";
	} else if (happy > sad) {
		cout << "happy";
	} else if (sad > happy) {
		cout << "sad";
	}
	return 0;
}