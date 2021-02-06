/* BOJ - 1389 케빈 베이컨의 6단계 법칙 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr int NODE_SIZE = 101;
constexpr int INF = 100'000'000;

int node, vertex;
vector<vector<int>> adj(NODE_SIZE);

void input() {
	cin >> node >> vertex;

	int from, to;
	for (int i = 0; i < vertex; i++) {
		cin >> from >> to;

		adj[from].push_back(to);
		adj[to].push_back(from);
	}
}

int bfs(const int start) {
	queue<int> q;
	vector<int> dist(node + 1, -1);

	q.push(start);
	dist[start] = 0;

	int sum = 0;
	while (!q.empty()) {
		int current = q.front();
		q.pop();

		for (int i = 0; i < adj[current].size(); i++) {
			int next = adj[current][i];

			if (dist[next] == -1) {
				q.push(next);
				dist[next] = dist[current] + 1;
				sum += dist[next];
			}
		}
	}

	return sum;
}

void solve() {
	input();

	vector<int> relations(node + 1, INF);
	for (int n = 1; n <= node; n++)
		relations[n] = bfs(n);

	int answer, min = INF;
	for (int n = 1; n <= node; n++) {
		if (relations[n] < min) {
			min = relations[n];
			answer = n;
		}
	}
	cout << answer << '\n';
}

int main() {
	solve();

	return 0;
}