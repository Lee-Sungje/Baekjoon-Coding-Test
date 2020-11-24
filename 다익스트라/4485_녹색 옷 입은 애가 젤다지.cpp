/* BOJ - 4485 녹색 옷 입은 애가 젤다지? */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> Pip;

constexpr int MAP_SIZE = 125;
constexpr int IMPOSSIBLE = -1;
constexpr int DIRECTION_X[] = { 0, 1, 0, -1 };
constexpr int DIRECTION_Y[] = { -1, 0, 1, 0 };

int map[MAP_SIZE][MAP_SIZE];
int cost[MAP_SIZE][MAP_SIZE];

bool isRange(int size, int x, int y) {
	return (0 <= x && x < size && 0 <= y && y < size) ? true : false;
}

bool isImpossible(int x, int y) {
	return (cost[y][x] == IMPOSSIBLE) ? true : false;
}

void input(int size) {
	for (int y = 0; y < size; y++)
		for (int x = 0; x < size; x++)
			cin >> map[y][x];
}

int dijkstra(int size) {
	memset(cost, IMPOSSIBLE, sizeof(cost));
	priority_queue<Pip> pq;
	
	cost[0][0] = map[0][0];
	pq.push({ -map[0][0], {0, 0} });

	while (!pq.empty()) {
		int currentX = pq.top().second.second;
		int currentY = pq.top().second.first;
		int currentCost = -pq.top().first;
		pq.pop();

		if (!isImpossible(currentX, currentY) && currentCost > cost[currentY][currentX])
			continue;

		for (int d = 0; d < 4; d++) {
			int nextX = currentX + DIRECTION_X[d];
			int nextY = currentY + DIRECTION_Y[d];

			if (isRange(size, nextX, nextY)) {
				int nextCost = currentCost + map[nextY][nextX];

				if (isImpossible(nextX, nextY) || nextCost < cost[nextY][nextX]) {
					cost[nextY][nextX] = nextCost;
					pq.push({ -nextCost, {nextY, nextX} });
				}
			}
		}
	}

	return cost[size - 1][size - 1];
}

void solve() {
	int testcase = 0;
	while (true) {
		int size;

		cin >> size;
		if (size == 0) {
			break;
		} else {
			input(size);
			printf("Problem %d: %d\n", ++testcase, dijkstra(size));
		}
	}
}

int main(void) {
	solve();

	return 0;
}