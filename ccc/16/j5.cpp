#include <bits/stdc++.h>
using namespace std;

int main() {
	int question, rep, totalSpeed = 0;
	cin >> question >> rep;
	vector<int> speed1(rep);
	vector<int> speed2(rep);

	cin.ignore(1);
	{
		string buffer, numBuffer;
		int numNum = 0;
		getline(cin, buffer);
		for (int j = 0; j < buffer.size(); j++) {
			if (buffer.at(j) == ' ') {
				speed1.at(numNum) = atoi(numBuffer.c_str());
				numBuffer = "";
				numNum++;
			} else {
				numBuffer.push_back(buffer.at(j));
			}
		}
		speed1.at(numNum) = atoi(numBuffer.c_str());
	}
	{
		string buffer, numBuffer;
		int numNum = 0;
		getline(cin, buffer);
		for (int j = 0; j < buffer.size(); j++) {
			if (buffer.at(j) == ' ') {
				speed2.at(numNum) = atoi(numBuffer.c_str());
				numBuffer = "";
				numNum++;
			} else {
				numBuffer.push_back(buffer.at(j));
			}
		}
		speed2.at(numNum) = atoi(numBuffer.c_str());
	}

	// max speed = put the fast ppl with slow ppl lmao
	// min speed = put the fat ppl with the fat ppl lmao
	sort(speed1.begin(), speed1.end());
	sort(speed2.begin(), speed2.end());
	if (question == 1) {
		for (int i = 0; i < rep; i++) {
			totalSpeed += max(speed1.at(i), speed2.at(i));
			// cout << "added: " << max(speed1.at(i), speed1.at(i)) << " from "
		}
		cout << totalSpeed;
	} else if (question == 2) {
		for (int i = 0; i < rep; i++) {
			totalSpeed += max(speed1.at(i), speed2.at(rep - (i + 1)));
		}
		cout << totalSpeed;
	}
	return 0;
}