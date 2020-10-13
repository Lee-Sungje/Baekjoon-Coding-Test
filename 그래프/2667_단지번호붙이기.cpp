/* BOJ - 2667 단지번호붙이기 */

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int MAP_SIZE = 25;
constexpr int DIRECTION_X[4] = { -1, 1, 0, 0 }; // [0]: Up, [1]: Down, [2]: Right, [3]: Left
constexpr int DIRECTION_Y[4] = { 0, 0, 1, -1 }; // [0]: Up, [1]: Down, [2]: Right, [3]: Left

int n;
int a[MAP_SIZE][MAP_SIZE];
int d[MAP_SIZE][MAP_SIZE];
int answer[MAP_SIZE * MAP_SIZE];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++)
			a[i][j] = str[j] - '0';
	}
}

void result(int block) {
	cout << block << '\n';
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			answer[d[i][j]] += 1;

	sort(answer + 1, answer + block + 1);
	for (int i = 1; i <= block; i++)
		cout << answer[i] << '\n';
}

void bfs(int i, int j, int block) {
	queue<pair<int, int>> q;
	q.push({ i, j });
	d[i][j] = block;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();

		for (int direction = 0; direction < 4; direction++) {
			int nowX = x + DIRECTION_X[direction];
			int nowY = y + DIRECTION_Y[direction];
			if (0 <= nowX && nowX < n && 0 <= nowY && nowY < n) {
				if (a[nowX][nowY] == 1 && d[nowX][nowY] == 0) {
					q.push({ nowX, nowY });
					d[nowX][nowY] = block;
				}
			}
		}
	}
}

void solve() {
	input();

	int block = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] == 1 && d[i][j] == 0)
				bfs(i, j, ++block);
	result(block);
}

int main(void) {
	solve();

	return 0;
}