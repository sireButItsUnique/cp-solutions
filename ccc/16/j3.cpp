#include <bits/stdc++.h>
using namespace std;

int main() {
	string code, subCode;
	int annagram = 0;
	cin >> code;

	if (code.size() == 1) {
		cout << 1;
		return 0;
	}

	for (int i = 0; i < code.size(); i++) {
		subCode = code.at(i);
		for (int j = i + 1; j < code.size(); j++) {
			subCode.push_back(code.at(j));
			string buffer = subCode;
			reverse(buffer.begin(), buffer.end());
			if (buffer == subCode) {
				if (buffer.size() > annagram) {
					annagram = buffer.size();
				}
			}
		}
	}

	cout << annagram;
	return 0;
}