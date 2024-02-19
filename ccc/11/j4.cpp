#include <bits/stdc++.h>
using namespace std;

int mapX(int x) { return 200 + x; }
int mapY(int y) { return (y * -1) - 1; }

int main() {
	// setting up hole
	bool hole[401][200];
	int drill[2] = {-1, -5};
	for (int i = 0; i < 401; i++) {
		for (int j = 0; j < 200; j++) {
			hole[i][j] = false;
		}
	}
	hole[mapX(0)][mapY(-1)] = true;
	hole[mapX(0)][mapY(-2)] = true;
	hole[mapX(0)][mapY(-3)] = true;
	hole[mapX(1)][mapY(-3)] = true;
	hole[mapX(2)][mapY(-3)] = true;
	hole[mapX(3)][mapY(-3)] = true;
	hole[mapX(3)][mapY(-4)] = true;
	hole[mapX(3)][mapY(-5)] = true;
	hole[mapX(4)][mapY(-5)] = true;
	hole[mapX(5)][mapY(-5)] = true;
	hole[mapX(5)][mapY(-4)] = true;
	hole[mapX(5)][mapY(-3)] = true;
	hole[mapX(6)][mapY(-3)] = true;
	for (int i = -3; i > -8; i--) {
		hole[mapX(7)][mapY(i)] = true;
	}
	for (int i = -1; i < 8; i++) {
		hole[mapX(i)][mapY(-7)] = true;
	}
	hole[mapX(-1)][mapY(-6)] = true;
	hole[mapX(-1)][mapY(-5)] = true;

	while (true) {
		// getting input
		char cmd;
		int pram;
		cin >> cmd >> pram;
		if (cmd == 'q') {
			return 0;
		}

		// drilling
		if (cmd == 'r') {
			for (int i = drill[0] + 1; i <= drill[0] + pram; i++) {
				// if hole alr there
				if (hole[mapX(i)][mapY(drill[1])]) {
					cout << drill[0] + pram << " " << drill[1] << " DANGER";
					return 0;
				}

				// making hole
				hole[mapX(i)][mapY(drill[1])] = true;
			}
			drill[0] += pram;
			cout << drill[0] << " " << drill[1] << " safe\n";
		} else if (cmd == 'l') {
			for (int i = drill[0] - 1; i >= drill[0] - pram; i--) {
				// if hole alr there
				if (hole[mapX(i)][mapY(drill[1])]) {
					cout << drill[0] - pram << " " << drill[1] << " DANGER";
					return 0;
				}

				// making hole
				hole[mapX(i)][mapY(drill[1])] = true;
			}
			drill[0] -= pram;
			cout << drill[0] << " " << drill[1] << " safe\n";
		} else if (cmd == 'd') {
			for (int i = drill[1] - 1; i >= drill[1] - pram; i--) {
				// if hole alr there
				if (hole[mapX(drill[0])][mapY(i)]) {
					cout << drill[0] << " " << drill[1] - pram << " DANGER";
					return 0;
				}

				// making hole
				hole[mapX(drill[0])][mapY(i)] = true;
			}
			drill[1] -= pram;
			cout << drill[0] << " " << drill[1] << " safe\n";
		} else if (cmd == 'u') {
			for (int i = drill[1] + 1; i <= drill[1] + pram; i++) {
				// if hole alr there
				if (hole[mapX(drill[0])][mapY(i)]) {
					cout << drill[0] << " " << drill[1] + pram << " DANGER";
					return 0;
				}

				// making hole
				hole[mapX(drill[0])][mapY(i)] = true;
			}
			drill[1] += pram;
			cout << drill[0] << " " << drill[1] << " safe\n";
		}
	}
	return 0;
}