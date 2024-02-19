#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		char s;
		cin >> num >> s;
		for (int j = 0; j < num; j++) {
			cout << s;
		}
		cout << endl;
	}

	return 0;
}