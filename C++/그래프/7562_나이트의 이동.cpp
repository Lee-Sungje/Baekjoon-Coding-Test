/* BOJ - 7562 나이트의 이동 */

#include <iostream>
#include <queue>

using namespace std;

constexpr int BOARD_SIZE = 300;
constexpr int DIRECTION = 8;
constexpr int DIRECTION_X[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
constexpr int DIRECTION_Y[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int l;
bool isVisit[BOARD_SIZE][BOARD_SIZE];
int answer[BOARD_SIZE][BOARD_SIZE];
pair<int, int> current;
pair<int, int> target;

void init() {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			isVisit[i][j] = false;
			answer[i][j] = 0;
		}
	}
}

void input() {
	cin >> l;
	cin >> current.first >> current.second;
	cin >> target.first >> target.second;
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	isVisit[x][y] = true;
	answer[x][y] = 0;

	while (!q.empty()) {
		int currentX = q.front().first;
		int currentY = q.front().second;
		q.pop();
		for (int d = 0; d < DIRECTION; d++) {
			int nextX = currentX + DIRECTION_X[d];
			int nextY = currentY + DIRECTION_Y[d];

			if (0 <= nextX && nextX < l && 0 <= nextY && nextY < l) {
				if (!isVisit[nextX][nextY]) {
					q.push({ nextX, nextY });
					isVisit[nextX][nextY] = true;
					answer[nextX][nextY] = answer[currentX][currentY] + 1;
				}
			}
		}
	}
}

void solve() {
	int t;
	cin >> t;
	while (t--) {
		init();
		input();
		bfs(current.first, current.second);
		cout << answer[target.first][target.second] << '\n';
	}
}

int main(void) {
	solve();

	return 0;
}