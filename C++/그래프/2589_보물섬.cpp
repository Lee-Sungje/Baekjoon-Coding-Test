/* BOJ - 2589 보물섬 */

#include <cstring>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

constexpr int MAP_SIZE = 50;
constexpr int DIRECTION = 4;
constexpr int DIRECTION_X[] = { -1, 0, 1, 0 };
constexpr int DIRECTION_Y[] = { 0, 1, 0, -1 };

int height, width;
char map[MAP_SIZE][MAP_SIZE];
int dist[MAP_SIZE][MAP_SIZE];

void input() {
	cin >> height >> width;

	for (int h = 0; h < height; h++) {
		string str;
		cin >> str;
		for (int w = 0; w < width; w++)
			map[h][w] = str[w];
	}		
}

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	dist[x][y] = 0;

	int maximum = 0;
	while (!q.empty()) {
		int currentX = q.front().first;
		int currentY = q.front().second;
		q.pop();

		for (int d = 0; d < DIRECTION; d++) {
			int nextX = currentX + DIRECTION_X[d];
			int nextY = currentY + DIRECTION_Y[d];

			if (0 <= nextX && nextX < height && 0 <= nextY && nextY < width) {
				if (map[nextX][nextY] == 'L' && dist[nextX][nextY] == -1) {
					q.push({ nextX, nextY });
					dist[nextX][nextY] = dist[currentX][currentY] + 1;
					if (maximum < dist[nextX][nextY])
						maximum = dist[nextX][nextY];
				}
			}
		}
	}
	return maximum;
}

void solve() {
	input();

	int answer = 0;
	for (int x = 0; x < height; x++) {
		for (int y = 0; y < width; y++) {
			if (map[x][y] == 'L') {
				memset(dist, -1, sizeof(dist));
				answer = max(bfs(x, y), answer);
			}
		}
	}
	cout << answer << '\n';
}

int main(void) {
	solve();

	return 0;
}