/* BOJ - 11403 경로 찾기 */

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr int MAX_VERTEX = 100;

int n;
int answer[MAX_VERTEX][MAX_VERTEX];
vector<int> adj[MAX_VERTEX];
bool isVisit[MAX_VERTEX];

void input() {
	cin >> n;
	for (int from = 0; from < n; from++) {
		for (int to = 0; to < n; to++) {
			cin >> answer[from][to];
			if (answer[from][to] == 1)
				adj[from].push_back(to);
		}
	}
}

void output() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << answer[i][j] << ' ';
		cout << '\n';
	}
}

void bfs(int from) {
	queue<int> q;
	q.push(from);

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		for (int i = 0; i < adj[current].size(); i++) {
			int to = adj[current][i];

			if (!isVisit[to]) {
				isVisit[to] = true;
				answer[from][to] = 1;
				q.push(to);
			}
		}
	}
}

void solve() {
	input();
	for (int i = 0; i < n; i++) {
		memset(isVisit, false, sizeof(isVisit));
		bfs(i);
	}
	output();
}

int main(void) {
	solve();

	return 0;
}