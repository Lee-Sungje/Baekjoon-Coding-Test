/* BOJ - 1012 유기농 배추 */

#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

constexpr int MAP_SIZE = 50;
constexpr int DIRECTION = 4;
constexpr int DIRECTION_X[] = { 0, 1, 0, -1 };
constexpr int DIRECTION_Y[] = { -1, 0, 1, 0 };

int m, n, k;
bool map[MAP_SIZE][MAP_SIZE];
int scope[MAP_SIZE][MAP_SIZE];

void init() {
	memset(map, false, sizeof(map));
	memset(scope, 0, sizeof(scope));
}

void input() {
	cin >> m >> n >> k;

	for (int count = 0; count < k; count++) {
		int x, y;
		cin >> x >> y;
		map[y][x] = true;
	}
}

void bfs(int y, int x, int worm) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	scope[y][x] = worm;

	while (!q.empty()) {
		int currentY = q.front().first;
		int currentX = q.front().second;
		q.pop();

		for (int d = 0; d < DIRECTION; d++) {
			int nextY = currentY + DIRECTION_Y[d];
			int nextX = currentX + DIRECTION_X[d];

			if (0 <= nextY && nextY < n && 0 <= nextX && nextX < m) {
				if (map[nextY][nextX] && scope[nextY][nextX] != worm) {
					q.push({ nextY, nextX });
					scope[nextY][nextX] = worm;
				}
			}
		}
	}
}

void solve() {
	int testcase;
	cin >> testcase;

	while (testcase--) {
		init();
		input();
		int worm = 0;

		for (int y = 0; y < n; y++)
			for (int x = 0; x < m; x++)
				if (map[y][x] && scope[y][x] == 0)
					bfs(y, x, ++worm);

		cout << worm << '\n';
	}
}

int main(void) {
	solve();

	return 0;
}