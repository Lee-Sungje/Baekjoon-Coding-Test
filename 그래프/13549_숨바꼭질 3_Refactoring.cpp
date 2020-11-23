/* BOJ - 13549 숨바꼭질 3 Refactoring */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> P;
constexpr int MAX_VERTEX = 100'001;
constexpr int IMPOSSIBLE = -1;
constexpr int TELEPORT = 0;
constexpr int MOVE[] = { 2, -1, 1 };

int start, goal;

bool isRange(int vertex) {
	return (0 <= vertex && vertex < MAX_VERTEX) ? true : false;
}

int bfs(int start, int goal) {
	vector<int> answer(MAX_VERTEX, IMPOSSIBLE);
	deque<int> dq;

	dq.push_back(start);
	answer[start] = 0;

	while (!dq.empty()) {
		int current = dq.front();
		dq.pop_front();
		
		if (current == goal) break;

		for (int m = 0; m < 3; m++) {
			int next;

			if (m == TELEPORT) {
				next = current * MOVE[m];
				if (isRange(next) && answer[next] == IMPOSSIBLE) {
					answer[next] = answer[current];
					dq.push_front(next);
				}
			} else {
				next = current + MOVE[m];
				if (isRange(next) && answer[next] == IMPOSSIBLE) {
					answer[next] = answer[current] + 1;
					dq.push_back(next);
				}
			}
		}
	}

	return answer[goal];
}

void solve() {
	cin >> start >> goal;
	cout << bfs(start, goal) << '\n';
}

int main(void) {
	solve();

	return 0;
}