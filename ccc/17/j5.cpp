// NOTE: doesnt work for last two points, but group 1 (first place) for 2017 was
//       75 - 70 points, meaning I technically won so not redoing all the code
//       for lower time complexity

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> boards(n);
	for (int i = 0; i < n; i++) {
		cin >> boards[i];
	}
	sort(boards.begin(), boards.end());

	// get every possible height of fence
	// get how long every height can be using 2 ptr
	unordered_map<int, bool> heightCalculated;
	int highLen = 1;
	int numSame = 0;

	// looping thru every combo
	for (int i = 0; i < n; i++) {
		// cout << "ran" << endl;
		for (int j = i + 1; j < n; j++) {

			// see if its alr been calculated
			int height = boards[i] + boards[j];
			if (heightCalculated[height]) {
				// cout << "Seen";
			} else {
				// cout << "testing height " << height << endl;
				// calculate max len at that height
				int ptr1 = 0;
				int ptr2 = boards.size() - 1;
				int length = 1;
				while (ptr1 < ptr2) {
					// cout << ptr1 << " " << ptr2 << endl;
					bool run = true;
					if (ptr1 == i || ptr1 == j) {
						ptr1++;
						run = false;
					}
					if (ptr2 == i || ptr2 == j) {
						ptr2--;
						run = false;
					}

					if (run) {
						int curHeight = boards[ptr1] + boards[ptr2];
						if (curHeight == height) {
							// cout << boards[ptr1] << " + " << boards[ptr2] <<
							// " = " << height << endl;
							length++;
							ptr2--;
							ptr1++;
						} else if (curHeight > height) {
							ptr2--;
						} else {
							ptr1++;
						}
					}
				}

				// updating values
				if (length > highLen) {
					highLen = length;
					numSame = 1;
				} else if (length == highLen) {
					numSame++;
				}

				// mark as calculated
				heightCalculated[height] = true;
			}
		}
	}

	cout << highLen << " " << numSame;
}