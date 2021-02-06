/* BOJ - 2146 다리 만들기 */

#include <iostream>
#include <queue>

using namespace std;

constexpr int MAP_SIZE = 100;
constexpr int DIRECTION = 4;
constexpr int DIRECTION_X[] = { -1, 0, 1, 0 };
constexpr int DIRECTION_Y[] = { 0, 1, 0, -1 };

int n;
bool map[MAP_SIZE][MAP_SIZE];
int dist[MAP_SIZE][MAP_SIZE];
int group[MAP_SIZE][MAP_SIZE];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
}

void grouping(int x, int y, int block) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	group[x][y] = block;

	while (!q.empty()) {
		int currentX = q.front().first;
		int currentY = q.front().second;
		q.pop();

		for (int d = 0; d < DIRECTION; d++) {
			int nextX = currentX + DIRECTION_X[d];
			int nextY = currentY + DIRECTION_Y[d];

			if (0 <= nextX && nextX < n && 0 <= nextY && nextY < n) {
				if (map[nextX][nextY] && group[nextX][nextY] == 0) {
					q.push({ nextX, nextY });
					group[nextX][nextY] = block;
				}
			}
		}
	}
}

void bfs() {
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = -1;
			if (map[i][j]) {
				q.push({ i, j });
				dist[i][j] = 0;
			}				
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int d = 0; d < DIRECTION; d++) {
			int nextX = x + DIRECTION_X[d];
			int nextY = y + DIRECTION_Y[d];

			if (0 <= nextX && nextX < n && 0 <= nextY && nextY < n) {
				if (dist[nextX][nextY] == -1) {
					group[nextX][nextY] = group[x][y];
					dist[nextX][nextY] = dist[x][y] + 1;
					q.push({ nextX, nextY });
				}
			}
		}
	}
}

int result() {
	int answer = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int d = 0; d < DIRECTION; d++) {
				int x = i + DIRECTION_X[d];
				int y = j + DIRECTION_Y[d];

				if (0 <= x && x < n && 0 <= y && y < n)
					if (group[i][j] != group[x][y])
						if (answer == -1 || answer > dist[i][j] + dist[x][y])
							answer = dist[i][j] + dist[x][y];
			}
		}
	}

	return answer;
}

void solve() {
	input();

	int block = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (map[i][j] && group[i][j] == 0)
				grouping(i, j, ++block);

	bfs();
	cout << result() << '\n';
}

int main(void) {
	solve();
	
	return 0;
}