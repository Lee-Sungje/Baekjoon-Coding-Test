/* BOJ - 7569 토마토 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

constexpr int BOX_SIZE = 100;
constexpr int DIRECTION = 6;
constexpr int DIRECTION_X[] = { 0, 1, 0, -1, 0, 0 };
constexpr int DIRECTION_Y[] = { -1, 0, 1, 0, 0, 0 };
constexpr int DIRECTION_Z[] = { 0, 0, 0, 0, 1, -1 };

struct Position {
	int x, y, z;

	Position(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};

int m, n, h;
int box[BOX_SIZE][BOX_SIZE][BOX_SIZE];
int dist[BOX_SIZE][BOX_SIZE][BOX_SIZE];
queue<Position> q;

void input() {
	cin >> m >> n >> h;
	
	for (int z = 0; z < h; z++)
		for (int y = 0; y < n; y++)
			for (int x = 0; x < m; x++)
				cin >> box[z][y][x];
}

bool isRange(int x, int y, int z) {
	if (x < 0 || m <= x) return false;
	if (y < 0 || n <= y) return false;
	if (z < 0 || h <= z) return false;

	return true;
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();

		for (int d = 0; d < DIRECTION; d++) {
			int nextX = x + DIRECTION_X[d];
			int nextY = y + DIRECTION_Y[d];
			int nextZ = z + DIRECTION_Z[d];

			if (isRange(nextX, nextY, nextZ)) {
				if (box[nextZ][nextY][nextX] == 0 && dist[nextZ][nextY][nextX] == -1) {
					q.push(Position(nextX, nextY, nextZ));
					box[nextZ][nextY][nextX] = 1;
					dist[nextZ][nextY][nextX] = dist[z][y][x] + 1;
				}
			}
		}
	}
}

void solve() {
	input();
	memset(dist, -1, sizeof(dist));
	for (int z = 0; z < h; z++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (box[z][y][x] == 1) {
					q.push(Position(x, y, z));
					dist[z][y][x] = 0;
				}
			}
		}
	}
	bfs();
	int answer = 0;
	for (int z = 0; z < h; z++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (box[z][y][x] == 0) {
					cout << -1 << '\n';
					return;
				}

				answer = answer < dist[z][y][x] ? dist[z][y][x] : answer;
			}
		}
	}
	cout << answer << '\n';
}

int main(void) {
	solve();

	return 0;
}