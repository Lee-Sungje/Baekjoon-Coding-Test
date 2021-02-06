/* BOJ - 13549 숨바꼭질 3 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> P;
constexpr int MAX_VERTEX = 100'001;
constexpr int INF = 100'000'000;
constexpr int TELEPORT = 0;
constexpr int MOVE[] = { 2, -1, 1 };

int start, goal;

bool isRange(int vertex) {
	return (0 <= vertex && vertex < MAX_VERTEX) ? true : false;
}

int dijkstra(int start, int goal) {
	vector<int> answer(MAX_VERTEX, INF);
	priority_queue<P> pq;

	pq.push({ 0, start });
	answer[start] = 0;

	while (!pq.empty()) {
		int current = pq.top().second;
		int currentCost = -pq.top().first;
		pq.pop();

		if (current == goal) break;
		if (answer[current] < currentCost) continue;

		for (int m = 0; m < 3; m++) {
			int next, nextCost;
			if (m == TELEPORT) {
				next = current * MOVE[m];
				nextCost = currentCost;
			} else {
				next = current + MOVE[m];
				nextCost = currentCost + 1;
			}

			if (isRange(next) && nextCost < answer[next]) {
				answer[next] = nextCost;
				pq.push({ -nextCost, next });
			}
		}
	}

	return answer[goal];
}

void solve() {
	cin >> start >> goal;
	cout << dijkstra(start, goal) << '\n';
}

int main(void) {
	solve();

	return 0;
}