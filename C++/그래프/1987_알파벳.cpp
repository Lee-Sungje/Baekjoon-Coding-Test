/* BOJ - 1987 알파벳 */

#include <iostream>
#include <string>

using namespace std;

constexpr int BOARD_SIZE = 20;
constexpr int ALPHABET_LENGTH = 26;
constexpr int DIRECTION = 4;
constexpr int DIRECTION_X[] = { -1, 0, 1, 0 };
constexpr int DIRECTION_Y[] = { 0, 1, 0, -1 };

int r, c, answer = 1;
char board[BOARD_SIZE][BOARD_SIZE];
bool isVisit[ALPHABET_LENGTH];

void input() {
	cin >> r >> c;
	
	for (int x = 0; x < r; x++) {
		string str;
		cin >> str;
		for (int y = 0; y < c; y++)
			board[x][y] = str[y];
	}
}

void dfs(int x, int y, int count) {
	answer = answer < count ? count : answer;

	for (int d = 0; d < DIRECTION; d++) {
		int nextX = x + DIRECTION_X[d];
		int nextY = y + DIRECTION_Y[d];

		if (0 <= nextX && nextX < r && 0 <= nextY && nextY < c) {
			if (!isVisit[board[nextX][nextY] - 'A']) {
				isVisit[board[nextX][nextY] - 'A'] = true;
				dfs(nextX, nextY, count + 1);
				isVisit[board[nextX][nextY] - 'A'] = false;
			}
		}
	}
}

void solve() {
	input();
	isVisit[board[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << answer << '\n';
}

int main(void) {
	solve();

	return 0;
}