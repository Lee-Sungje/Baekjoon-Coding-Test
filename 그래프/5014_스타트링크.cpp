/* BOJ - 5014 스타트링크 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr int MINUS_ONE = -1;

bool isRange(const int floor, const int current) {
	return (1 <= current && current <= floor) ? true : false;
}

int bfs(const int floor, const int start, const int goal,
		const int up, const int down) {
	vector<int> button = { up, -down };
	vector<int> count(floor + 1, MINUS_ONE);
	queue<int> q;

	q.push(start);
	count[start] = 0;

	while (!q.empty()) {
		int currentFloor = q.front();
		q.pop();

		for (int btn : button) {
			int nextFloor = currentFloor + btn;
			if (isRange(floor, nextFloor) && count[nextFloor] == MINUS_ONE) {
				q.push(nextFloor);
				count[nextFloor] = count[currentFloor] + 1;
			}
		}
	}

	return count[goal];
}

void solve() {
	int floor, start, goal, up, down;
	cin >> floor >> start >> goal >> up >> down;

	int answer = bfs(floor, start, goal, up, down);
	if (answer == MINUS_ONE)
		cout << "use the stairs" << '\n';
	else
		cout << answer << '\n';
}

int main() {
	solve();

	return 0;
}