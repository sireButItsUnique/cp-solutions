#include <bits/stdc++.h>
using namespace std;

int calculate(string currentTime) {
	int difference = (currentTime.at(1) - '0') - (currentTime.at(0) - '0');
	for (int i = 2; i < currentTime.size(); i++) {
		if (currentTime.at(i) - currentTime.at(i - 1) != difference) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int favTime = 0;
	int minsWatched;
	cin >> minsWatched;
	int mins = 720 + minsWatched;

	if (minsWatched >= 720) {
		int leftovers = minsWatched % 720;
		for (int i = 1; i <= leftovers; i++) {
			int mins = 720 + i;

			if (i >= 60) {
				if ((mins % 60) < 10) {
					favTime +=
						calculate(to_string((mins - (mins % 60)) / 60 - 12) +
								  "0" + to_string(mins % 60));
				} else {
					favTime +=
						calculate(to_string((mins - (mins % 60)) / 60 - 12) +
								  to_string(mins % 60));
				}
			} else {
				if ((mins % 60) < 10) {
					favTime += calculate(to_string((mins - (mins % 60)) / 60) +
										 "0" + to_string(mins % 60));
				} else {
					favTime += calculate(to_string((mins - (mins % 60)) / 60) +
										 to_string(mins % 60));
				}
			}
		}
		favTime += 31 * ((minsWatched - (minsWatched % 720)) / 720);
	} else {
		for (int i = 1; i <= minsWatched; i++) {
			int mins = 720 + i;

			if (i >= 60) {
				if ((mins % 60) < 10) {
					favTime +=
						calculate(to_string((mins - (mins % 60)) / 60 - 12) +
								  "0" + to_string(mins % 60));
				} else {
					favTime +=
						calculate(to_string((mins - (mins % 60)) / 60 - 12) +
								  to_string(mins % 60));
				}
			} else {
				if ((mins % 60) < 10) {
					favTime += calculate(to_string((mins - (mins % 60)) / 60) +
										 "0" + to_string(mins % 60));
				} else {
					favTime += calculate(to_string((mins - (mins % 60)) / 60) +
										 to_string(mins % 60));
				}
			}
		}
	}
	cout << favTime;
	return 0;
}