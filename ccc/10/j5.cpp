#include <bits/stdc++.h>
using namespace std;

bool check(int x, int y, int xInc, int yInc) {
	x += xInc;
	y += yInc;
	if (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
		return true;
	}
	return false;
}

int main() {
	// input
	int start[2], end[2];
	int board[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
					   {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
					   {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
					   {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
	cin >> start[0] >> start[1] >> end[0] >> end[1];
	start[0]--;
	start[1]--;
	end[0]--;
	end[1]--;
	board[start[0]][start[1]] = 1;

	// cycling thru all moves
	int numMoves = 0;
	while (true) {
		// checking if end move has been hit
		if (board[end[0]][end[1]]) {
			cout << numMoves;
			return 0;
		}

		// jump from every pos
		int newBoard[8][8]{}; // make new array
		memcpy(newBoard, board, sizeof(board));

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j]) {
					// execute for each pos
					if (check(i, j, 1, 2)) {
						newBoard[i + 1][j + 2] = 1;
					}
					if (check(i, j, 1, -2)) {
						newBoard[i + 1][j + -2] = 1;
					}
					if (check(i, j, -1, 2)) {
						newBoard[i + -1][j + 2] = 1;
					}
					if (check(i, j, -1, -2)) {
						newBoard[i + -1][j + -2] = 1;
					}
					if (check(i, j, 2, 1)) {
						newBoard[i + 2][j + 1] = 1;
					}
					if (check(i, j, 2, -1)) {
						newBoard[i + 2][j + -1] = 1;
					}
					if (check(i, j, -2, 1)) {
						newBoard[i + -2][j + 1] = 1;
					}
					if (check(i, j, -2, -1)) {
						newBoard[i + -2][j + -1] = 1;
					}
				}
			}
		}
		memcpy(board, newBoard, sizeof(board));
		numMoves++;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				// cout << board[i][j] << " ";
			}
			// cout << endl;
		}
	}
}
