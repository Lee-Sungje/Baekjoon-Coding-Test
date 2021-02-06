/* BOJ - 2178 미로 탐색 */

#include <iostream>
#include <string>
#include <queue>

using namespace std;

constexpr int MAP_SIZE = 101;
constexpr int DIRECTION = 4;
constexpr int DIRECTION_X[DIRECTION] = { -1, 0, 1, 0 }; // [0]: N, [1]: E, [2]: S, [3]: W 
constexpr int DIRECTION_Y[DIRECTION] = { 0, 1, 0, -1 }; // [0]: N, [1]: E, [2]: S, [3]: W

int n, m;
bool map[MAP_SIZE][MAP_SIZE];
bool isVisit[MAP_SIZE][MAP_SIZE];
int answer[MAP_SIZE][MAP_SIZE];

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++)
			map[i][j] = str[j - 1] - '0';
	}
}

void bfs(int x = 1, int y = 1) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	isVisit[x][y] = true;
	answer[x][y] = 1;
	while (!q.empty()) {
		int currentX = q.front().first;
		int currentY = q.front().second;
		q.pop();

		for (int d = 0; d < DIRECTION; d++) {
			int nextX = DIRECTION_X[d] + currentX;
			int nextY = DIRECTION_Y[d] + currentY;

			if (0 < nextX && nextX <= n && 0 < nextY && nextY <= m) {
				if (map[nextX][nextY] && !isVisit[nextX][nextY]) {
					q.push({ nextX, nextY });
					isVisit[nextX][nextY] = true;
					answer[nextX][nextY] = answer[currentX][currentY] + 1;
				}
			}
		}
	}

}

void solve() {
	input();
	bfs();
	cout << answer[n][m] << '\n';
}

int main(void) {
	solve();

	return 0;
}