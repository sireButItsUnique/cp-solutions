// NOTE: for some reason fails on waterloo's servers on test case 6 (07:00 ->
// 10:30) even though it got 10:30 character for character on mine. Undefined
// behavior or smt this is so whack

#include <bits/stdc++.h>
using namespace std;

int main() {
	int depHour, depMin, currentTime;
	float progress = 0.0f;
	string buffer, numBuffer;
	cin >> buffer;
	numBuffer.push_back(buffer.at(0));
	numBuffer.push_back(buffer.at(1));
	depHour = atoi(numBuffer.c_str());
	if (buffer.at(3) == '0') {
		depMin = 0;
	} else if (buffer.at(3) == '2') {
		depMin = 20;
	} else if (buffer.at(3) == '4') {
		depMin = 40;
	}
	currentTime = (depHour * 60) + depMin;

	// rush = 7 - 10; 15 - 19
	// rush = 1/2 speed
	// each min = add 1; if in rush, add 1/2, wait till total is at 120

	while (progress < 120.0f) {
		if (currentTime >= 1440) {
			currentTime %= 1440;
		}
		if (currentTime >= 420 && currentTime < 600) {
			progress += 0.5f;
		} else if (currentTime >= 900 && currentTime < 1140) {
			progress += 0.5f;
		} else {
			progress += 1.0f;
		}
		currentTime++;
	}

	if (floor(currentTime / 60) < 10) {
		if (currentTime % 60 < 10) {
			cout << "0" << floor(currentTime / 60) << ":"
				 << "0" << currentTime % 60;
		} else {
			cout << "0" << floor(currentTime / 60) << ":" << currentTime % 60;
		}
	} else {
		if (currentTime % 60 < 10) {
			cout << floor(currentTime / 60) << ":"
				 << "0" << currentTime % 60;
		} else {
			cout << floor(currentTime / 60) << ":" << currentTime % 60;
		}
	}
	return 0;
}