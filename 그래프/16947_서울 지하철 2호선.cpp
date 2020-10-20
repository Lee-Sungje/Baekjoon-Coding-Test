/* BOJ - 16947 서울 지하철 2호선 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int NOT_INCLUDE = -2;
constexpr int NOT_FOUND = -1;
constexpr int VISIT = 1;
constexpr int INCLUDE = 2;
constexpr int STATION_SIZE = 3000;

int n;
vector<int> station[STATION_SIZE];
int isVisit[STATION_SIZE];
int dist[STATION_SIZE];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int from, to;
		cin >> from >> to;
		station[from - 1].push_back(to - 1);
		station[to - 1].push_back(from - 1);
	}
}

void output() {
	for (int i = 0; i < n; i++)
		cout << dist[i] << ' ';
	cout << '\n';
}

int dfs(int current = 0, int previous = -1) {
	if (isVisit[current] == VISIT) return current;
	isVisit[current] = VISIT;

	for (int next : station[current]) {
		if (previous == next) continue;

		int result = dfs(next, current);
		if (result == NOT_INCLUDE) return NOT_INCLUDE;
		if (result >= 0) {
			isVisit[current] = INCLUDE;
			if (current == result)	return NOT_INCLUDE;
			else					return result;
		}
	}
	return NOT_FOUND;
}

void bfs() {
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (isVisit[i] == 2) {
			dist[i] = 0;
			q.push(i);
		} else {
			dist[i] = -1;
		}
	}

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int next : station[current]) {
			if (dist[next] == -1) {
				q.push(next);
				dist[next] = dist[current] + 1;
			}
		}
	}
}

void solve() {
	input();
	dfs();
	bfs();
	output();
}

int main(void) {
	solve();

	return 0;
}