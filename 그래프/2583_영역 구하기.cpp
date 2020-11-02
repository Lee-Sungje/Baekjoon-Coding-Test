/* BOJ - 2583 영역 구하기 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr int MAX_SIZE = 100;
constexpr int DIRECTION = 4;
constexpr int DIRECTION_X[] = { -1, 0, 1, 0 };
constexpr int DIRECTION_Y[] = { 0, 1, 0, -1 };

int m, n, k;
bool graph[MAX_SIZE][MAX_SIZE];
int area[MAX_SIZE][MAX_SIZE];
vector<int> answers;

void input() {
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;

		for (int x = x1; x < x2; x++)
			for (int y = y1; y < y2; y++)
				graph[x][y] = true;
	}
}

void output() {
	cout << answers.size() << '\n';
	for (int answer : answers)
		cout << answer << ' ';
	cout << '\n';
}

int bfs(int x, int y, int color) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	area[x][y] = color;
	int count = 1;

	while (!q.empty()) {
		int currentX = q.front().first;
		int currentY = q.front().second;
		q.pop();

		for (int d = 0; d < DIRECTION; d++) {
			int nextX = currentX + DIRECTION_X[d];
			int nextY = currentY + DIRECTION_Y[d];

			if (0 <= nextX && nextX < m && 0 <= nextY && nextY < n) {
				if (!graph[nextX][nextY] && area[nextX][nextY] != color) {
					q.push({ nextX, nextY });
					area[nextX][nextY] = color;
					count += 1;
				}
			}
		}
	}

	return count;
}

void solve() {
	input();

	int color = 0;
	for (int x = 0; x < m; x++)
		for (int y = 0; y < n; y++)
			if (!graph[x][y] && area[x][y] == 0)
				answers.push_back(bfs(x, y, ++color));

	sort(answers.begin(), answers.end());
	output();
}

int main(void) {
	solve();

	return 0;
}