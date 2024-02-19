#include <bits/stdc++.h>
using namespace std;

int main() {
	int rep;
	cin >> rep;
	int currentTime = 0;
	vector<int> waitTime, friendNum, sentTime;
	vector<bool> stillWaiting;

	cin.ignore(1);
	for (int i = 0; i < rep; i++) {
		string buffer, numBuffer;
		int pram;
		getline(cin, buffer);
		for (int j = 2; j < buffer.size(); j++) {
			numBuffer.push_back(buffer.at(j));
		}
		pram = atoi(numBuffer.c_str());

		// actual algorithm
		if (buffer.at(0) == 'W') {
			currentTime += pram - 1;
		} else if (buffer.at(0) == 'R') {
			// check if exists + add if not
			bool alrExists = false;
			for (int j = 0; j < friendNum.size(); j++) {
				if (pram == friendNum.at(j)) {
					alrExists = true;
					j = friendNum.size() + 4;
				}
			}
			if (!alrExists) {
				friendNum.push_back(pram);
				waitTime.push_back(0);
				sentTime.push_back(currentTime);
				stillWaiting.push_back(true);
			}

			// start timing
			for (int friendPos = 0; friendPos < friendNum.size(); friendPos++) {
				if (friendNum.at(friendPos) == pram) {
					sentTime.at(friendPos) = currentTime;
					stillWaiting.at(friendPos) = true;
					friendPos = friendNum.size() + 4;
				}
			}
			currentTime++;

		} else if (buffer.at(0) == 'S') {
			for (int friendPos = 0; friendPos < friendNum.size(); friendPos++) {
				if (friendNum.at(friendPos) == pram) {
					waitTime.at(friendPos) +=
						(currentTime - sentTime.at(friendPos));
					stillWaiting.at(friendPos) = false;
					friendPos = friendNum.size() + 4;
				}
			}
			currentTime++;
		}
	}

	vector<int> friendBuffer = friendNum;
	sort(friendBuffer.begin(), friendBuffer.end());
	for (int i = 0; i < friendBuffer.size(); i++) {
		for (int friendPos = 0; friendPos < friendNum.size(); friendPos++) {
			if (friendNum.at(friendPos) == friendBuffer.at(i)) {
				if (!stillWaiting.at(friendPos)) {
					cout << friendNum.at(friendPos) << " "
						 << waitTime.at(friendPos) << endl;
					friendPos = friendNum.size() + 4;
				} else {
					cout << friendNum.at(friendPos) << " -1" << endl;
					friendPos = friendNum.size() + 4;
				}
			}
		}
	}
	return 0;
}