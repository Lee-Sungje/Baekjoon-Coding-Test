/* BOJ - 7576 토마토 */

#include <iostream>
#include <queue>

using namespace std;

constexpr int BOX_SIZE = 1000;
constexpr int DIRECTION = 4;
constexpr int DIRECTION_X[] = { -1, 0, 1, 0 }; // [0]: N, [1]: E, [2]: S, [3]: W
constexpr int DIRECTION_Y[] = { 0, 1, 0, -1 }; // [0]: N, [1]: E, [2]: S, [3]: W

int n, m;
int box[BOX_SIZE][BOX_SIZE];
int answer[BOX_SIZE][BOX_SIZE];
queue<pair<int, int>> q;

void input() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) q.push({ i, j });
		}
	}
}

int check() {
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 0) return -1;
			if (max < answer[i][j]) max = answer[i][j];
		}
	}

	return max;
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int d = 0; d < DIRECTION; d++) {
			int nextX = x + DIRECTION_X[d];
			int nextY = y + DIRECTION_Y[d];
			if (0 <= nextX && nextX < n && 0 <= nextY && nextY < m) {
				if (box[nextX][nextY] == 0) {
					q.push({ nextX, nextY });
					box[nextX][nextY] = 1;
					answer[nextX][nextY] = answer[x][y] + 1;
				}
			}
		}
	}
}

void solve() {
	input();
	bfs();
	cout << check() << '\n';
}

int main(void) {
	solve();
	
	return 0;
}