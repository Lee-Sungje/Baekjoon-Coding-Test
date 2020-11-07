/* BOJ - 2573 빙산 */

#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

constexpr int MAP_SIZE = 300;
constexpr int DIRECTION = 4;
constexpr int DIRECTION_X[] = { 0, 1, 0, -1 };
constexpr int DIRECTION_Y[] = { -1, 0, 1, 0 };

int n, m;
int map[MAP_SIZE][MAP_SIZE];
bool isVisit[MAP_SIZE][MAP_SIZE];

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	isVisit[y][x] = true;

	while (!q.empty()) {
		int currentY = q.front().first;
		int currentX = q.front().second;
		q.pop();
		
		for (int d = 0; d < DIRECTION; d++) {
			int nextY = currentY + DIRECTION_Y[d];
			int nextX = currentX + DIRECTION_X[d];

			if (!isVisit[nextY][nextX] && map[nextY][nextX] == 0) {
				map[currentY][currentX] -= 1;
			} else if (!isVisit[nextY][nextX]) {
				q.push({ nextY, nextX });
				isVisit[nextY][nextX] = true;
			}
		}
		if (map[currentY][currentX] < 0)
			map[currentY][currentX] = 0;
	}
}

void solve() {
	input();

	int day = 0;
	while (true) {
		memset(isVisit, false, sizeof(isVisit));

		int block = 0;
		for (int y = 1; y < n - 1; y++) {
			for (int x = 1; x < m - 1; x++) {
				if (map[y][x] != 0 && !isVisit[y][x]) {
					bfs(x, y);
					block += 1;
				}
			}
		}

		if (1 < block) {
			cout << day << '\n';
			return;
		} else if (block == 0) {
			cout << 0 << '\n';
			return;
		} else {
			day += 1;
		}
	}
}

int main(void) {
	solve();

	return 0;
}