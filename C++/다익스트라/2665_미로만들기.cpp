/* BOJ - 2665 미로만들기 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> Pip;

constexpr int MAX_SIZE = 50;
constexpr int IMPOSSIBLE = -1;
constexpr int DIRECTION = 4;
constexpr int DIRECTION_X[] = { 0, 1, 0, -1 };
constexpr int DIRECTION_Y[] = { -1, 0, 1, 0 };

int n;
int map[MAX_SIZE][MAX_SIZE];
int cost[MAX_SIZE][MAX_SIZE];

void input() {
	cin >> n;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			scanf_s("%1d", &map[y][x]);
}

bool isImpossible(int x, int y) {
	return (cost[y][x] == IMPOSSIBLE) ? true : false;
}

bool isRange(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < n) ? true : false;
}

bool isWall(int x, int y) {
	return (map[y][x] == 0) ? true : false;
}

int dijkstra() {
	memset(cost, IMPOSSIBLE, sizeof(cost));
	priority_queue<Pip> pq;

	pq.push({ 0, {0, 0} });

	while (!pq.empty()) {
		int currentX = pq.top().second.second;
		int currentY = pq.top().second.first;
		int currentCost = -pq.top().first;
		pq.pop();

		if (!isImpossible(currentY, currentX) && cost[currentY][currentX] < currentCost)
			continue;

		for (int d = 0; d < DIRECTION; d++) {
			int nextX = currentX + DIRECTION_X[d];
			int nextY = currentY + DIRECTION_Y[d];

			if (isRange(nextX, nextY)) {
				int nextCost = currentCost + isWall(nextX, nextY);

				if (isImpossible(nextX, nextY) || cost[nextY][nextX] > nextCost) {
					pq.push({ -nextCost, {nextY, nextX} });
					cost[nextY][nextX] = nextCost;
				}
			}
		}
	}

	return cost[n - 1][n - 1];
}

void solve() {
	input();
	cout << dijkstra() << '\n';
}

int main(void) {
	solve();

	return 0;
}