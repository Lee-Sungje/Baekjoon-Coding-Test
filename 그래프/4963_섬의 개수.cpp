/* BOJ - 4963 섬의 개수 */

#include <iostream>
#include <queue>

using namespace std;

constexpr int MAP_SIZE = 50;
constexpr int DIRECTION = 8;
/* Direction: [0]: N, [1]: NE, [2]: E, [3]: SE, [4]: S, [5]: SW, [6]: W, [7]: NW */
constexpr int DIRECTION_X[DIRECTION] = { -1, -1, 0, 1, 1, 1, 0, -1 };
constexpr int DIRECTION_Y[DIRECTION] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int w, h;
bool map[MAP_SIZE][MAP_SIZE];

void input() {
	cin >> w >> h;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> map[i][j];
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	map[x][y] = false;

	while (!q.empty()) {
		int currentX = q.front().first;
		int currentY = q.front().second;
		q.pop();

		for (int d = 0; d < DIRECTION; d++) {
			int nextX = DIRECTION_X[d] + currentX;
			int nextY = DIRECTION_Y[d] + currentY;

			if (0 <= nextX && nextX < h && 0 <= nextY && nextY < w) {
				if (map[nextX][nextY]) {
					q.push({ nextX, nextY });
					map[nextX][nextY] = false;
				}
			}
		}
	}
}

void solve() {
	do {
		input();

		int answer = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j]) {
					answer += 1;
					bfs(i, j);
				}
			}
		}
		if (w | h) cout << answer << '\n';
	} while (w | h);
}

int main(void) {
	solve();

	return 0;
}