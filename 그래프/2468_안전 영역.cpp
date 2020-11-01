/* BOJ - 2468 안전 영역 */

#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

constexpr int MAP_MAS_SIZE = 100;
constexpr int DIRECTION = 4;
constexpr int DIRECTION_X[] = { -1, 0, 1, 0 };
constexpr int DIRECTION_Y[] = { 0, 1, 0, -1 };

int n, maxHeight = 0, answer = 1;
int map[MAP_MAS_SIZE][MAP_MAS_SIZE];
int safeZone[MAP_MAS_SIZE][MAP_MAS_SIZE];

void init() {
	memset(safeZone, -1, sizeof(safeZone));
}

void input() {
	cin >> n;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			cin >> map[x][y];
			if (maxHeight < map[x][y])
				maxHeight = map[x][y];
		}
	}
}

void bfs(int x, int y, int height, int zone) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	safeZone[x][y] = zone;

	while (!q.empty()) {
		int currentX = q.front().first;
		int currentY = q.front().second;
		q.pop();

		for (int d = 0; d < DIRECTION; d++) {
			int nextX = currentX + DIRECTION_X[d];
			int nextY = currentY + DIRECTION_Y[d];

			if (0 <= nextX && nextX < n && 0 <= nextY && nextY < n) {
				if (height < map[nextX][nextY] && safeZone[nextX][nextY] == -1) {
					q.push({ nextX, nextY });
					safeZone[nextX][nextY] = zone;
				}
			}
		}
	}
}

void solve() {
	input();

	for (int height = 1; height <= maxHeight; height++) {
		init();
		int zone = 0;
		for (int x = 0; x < n; x++)
			for (int y = 0; y < n; y++)
				if (height < map[x][y] && safeZone[x][y] == -1)
					bfs(x, y, height, ++zone);

		if (answer < zone)
			answer = zone;
	}
	cout << answer << '\n';
}

int main(void) {
	solve();

	return 0;
}