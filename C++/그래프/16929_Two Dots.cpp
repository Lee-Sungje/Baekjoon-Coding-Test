/* BOJ - 16929 Two Dots */

#include <iostream>
#include <string>

using namespace std;

constexpr int BOARD_SIZE = 50;
constexpr int DIRECTION = 4;
constexpr int DIRECTION_X[] = { -1, 0, 1, 0 };
constexpr int DIRECTION_Y[] = { 0, 1, 0, -1 };

int n, m;
char board[BOARD_SIZE][BOARD_SIZE];
bool isVisit[BOARD_SIZE][BOARD_SIZE];
int dist[BOARD_SIZE][BOARD_SIZE];

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
			board[i][j] = str[j];
	}
}

bool dfs(int x, int y, int count, char color) {
	if (isVisit[x][y]) return count - dist[x][y] >= 4;
	isVisit[x][y] = true;
	dist[x][y] = count;

	for (int d = 0; d < DIRECTION; d++) {
		int nextX = x + DIRECTION_X[d];
		int nextY = y + DIRECTION_Y[d];
		if (0 <= nextX && nextX < n && 0 <= nextY && nextY < m) {
			if (board[nextX][nextY] == color)
				if (dfs(nextX, nextY, count + 1, color))
					return true;
		}
	}
	return false;
}

bool solve() {
	input();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!isVisit[i][j])
				if (dfs(i, j, 0, board[i][j]))
					return true;
	return false;
}

int main(void) {
	if (solve())	cout << "Yes\n";
	else			cout << "No\n";

	return 0;
}