/* BOJ - 1261 알고스팟 */

#include <iostream>
#include <string>
#include <deque>

using namespace std;

constexpr int DIRECTION = 4;
constexpr int DIRECTION_X[] = { -1, 0, 1, 0 };
constexpr int DIRECTION_Y[] = { 0, 1, 0, -1 };
constexpr int MAZE_SIZE = 100;

int n, m;
bool maze[MAZE_SIZE][MAZE_SIZE];
int dist[MAZE_SIZE][MAZE_SIZE];

void input() {
	cin >> m >> n;
	for (int x = 0; x < n; x++) {
		string str;
		cin >> str;
		for (int y = 0; y < m; y++) {
			maze[x][y] = str[y] - '0';
			dist[x][y] = -1;
		}
	}
}

void bfs() {
	deque<pair<int, int>> deq;
	deq.push_back({ 0, 0 });
	dist[0][0] = 0;

	while (!deq.empty()) {
		int x = deq.front().first;
		int y = deq.front().second;
		deq.pop_front();

		for (int d = 0; d < DIRECTION; d++) {
			int nx = x + DIRECTION_X[d];
			int ny = y + DIRECTION_Y[d];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (dist[nx][ny] == -1) {
					if (maze[nx][ny]) {
						deq.push_back({ nx, ny });
						dist[nx][ny] = dist[x][y] + 1;
					} else {
						deq.push_front({ nx, ny });
						dist[nx][ny] = dist[x][y];
					}
				}
			}
		}
	}
}

void solve() {
	input();
	bfs();
	cout << dist[n - 1][m - 1] << '\n';
}

int main(void) {
	solve();

	return 0;
}