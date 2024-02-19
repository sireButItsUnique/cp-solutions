#include <bits/stdc++.h>
using namespace std;

int main() {
	string word;
	cin >> word;
	for (int i = 0; i < word.size(); i++) {
		if (!(word[i] == 'I' || word[i] == 'O' || word[i] == 'S' ||
			  word[i] == 'H' || word[i] == 'Z' || word[i] == 'X' ||
			  word[i] == 'N')) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}