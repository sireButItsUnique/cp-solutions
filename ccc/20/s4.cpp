#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

/*
BABCBCACCA
-brute force for every i location
-every i = every starting point for A section
-then try to do B or C next, after which last one will sort itself out
*/
vector<int> aCnt;
vector<int> bCnt;
vector<int> cCnt;

int countA(int start) {
	int s1 = (start ? aCnt[start - 1] : 0);
	int e1 = aCnt[min((int)aCnt.size() - 1, start + aCnt.back() - 1)];

	int s2 = 0;
	int e2 = (start + aCnt.back() - 1 >= aCnt.size() ? aCnt[start + aCnt.back() - 1 - aCnt.size()] : 0);

	return (e1 - s1) + (e2 - s2);
}

int countAInB(int start) {
	int s1 = (start ? aCnt[start - 1] : 0);
	int e1 = aCnt[min((int)aCnt.size() - 1, start + bCnt.back() - 1)];

	int s2 = 0;
	int e2 = (start + bCnt.back() - 1 >= aCnt.size() ? aCnt[start + bCnt.back() - 1 - aCnt.size()] : 0);

	return (e1 - s1) + (e2 - s2);
}

int countAInC(int start) {
	int s1 = (start ? aCnt[start - 1] : 0);
	int e1 = aCnt[min((int)aCnt.size() - 1, start + cCnt.back() - 1)];

	int s2 = 0;
	int e2 = (start + cCnt.back() - 1 >= aCnt.size() ? aCnt[start + cCnt.back() - 1 - aCnt.size()] : 0);

	return (e1 - s1) + (e2 - s2);
}

int countB(int start) {
	int s1 = (start ? bCnt[start - 1] : 0);
	int e1 = bCnt[min((int)bCnt.size() - 1, start + bCnt.back() - 1)];

	int s2 = 0;
	int e2 = (start + bCnt.back() - 1 >= bCnt.size() ? bCnt[start + bCnt.back() - 1 - bCnt.size()] : 0);

	return (e1 - s1) + (e2 - s2);
}

int countBInA(int start) {
	int s1 = (start ? bCnt[start - 1] : 0);
	int e1 = bCnt[min((int)bCnt.size() - 1, start + aCnt.back() - 1)];

	int s2 = 0;
	int e2 = (start + aCnt.back() - 1 >= bCnt.size() ? bCnt[start + aCnt.back() - 1 - bCnt.size()] : 0);

	return (e1 - s1) + (e2 - s2);
}

int countC(int start) {
	int s1 = (start ? cCnt[start - 1] : 0);
	int e1 = cCnt[min((int)cCnt.size() - 1, start + cCnt.back() - 1)];

	int s2 = 0;
	int e2 = (start + cCnt.back() - 1 >= cCnt.size() ? cCnt[start + cCnt.back() - 1 - cCnt.size()] : 0);

	return (e1 - s1) + (e2 - s2);
}

int countCInA(int start) {
	int s1 = (start ? cCnt[start - 1] : 0);
	int e1 = cCnt[min((int)cCnt.size() - 1, start + aCnt.back() - 1)];

	int s2 = 0;
	int e2 = (start + aCnt.back() - 1 >= cCnt.size() ? cCnt[start + aCnt.back() - 1 - cCnt.size()] : 0);

	return (e1 - s1) + (e2 - s2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	string s;
	cin >> s;

	// count how many of each letter so far
	aCnt.resize(s.size(), 0);
	bCnt.resize(s.size(), 0);
	cCnt.resize(s.size(), 0);
	aCnt[0] += (s[0] == 'A');
	bCnt[0] += (s[0] == 'B');
	cCnt[0] += (s[0] == 'C');
	for (int i = 1; i < s.size(); i++) {
		aCnt[i] = aCnt[i - 1] + (s[i] == 'A');
		bCnt[i] = bCnt[i - 1] + (s[i] == 'B');
		cCnt[i] = cCnt[i - 1] + (s[i] == 'C');
	}

	// loop thru every i for which a can start at
	ll res = INT_MAX;
	for (int i = 0; i < s.size(); i++) {

		// count how many are in sub are not A
		ll missingA = max(0, aCnt.back() - countA(i));

		// try either putting b or c next BABCBCACCA
		int newIdx = (i + aCnt.back()) % aCnt.size();

		// somehow segfaults (prob by going out of bounds) when theres no c, scuffed fix but its ccc so
		if (cCnt.back()) {
			ll missingB = max(0, bCnt.back() - countB(newIdx) - min(countBInA(i), countAInB(newIdx)));
			res = min(res, missingA + missingB);
			ll missingC = max(0, cCnt.back() - countC(newIdx) - min(countCInA(i), countAInC(newIdx)));
			res = min(res, missingA + missingC);
		} else {
			res = min(res, missingA);
		}
	}

	// return res
	cout << fixed << res;
	return 0;
}