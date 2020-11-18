/* BOJ - 1753 최단경로 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr int MAX_VERTEX = 20001;
constexpr int INF = 100'000'000;

int v, e, start;
vector<pair<int, int>> adj[MAX_VERTEX];
vector<int> answer;

void input() {
	cin >> v >> e;
	cin >> start;

	int from, to, weight;
	for (int i = 1; i <= e; i++) {
		cin >> from >> to >> weight;
		adj[from].push_back({ weight, to });
	}
}

void output() {
	for (int i = 1; i <= v; i++) {
		if (answer[i] == INF)
			cout << "INF" << '\n';
		else
			cout << answer[i] << '\n';
	}
}

vector<int> dijkstra() {
	vector<int> ans(v + 1, INF);
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	ans[start] = 0;

	while (!pq.empty()) {
		int current = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (ans[current] < cost) continue;

		for (int i = 0; i < adj[current].size(); i++) {
			int next = adj[current][i].second;
			int nextCost = adj[current][i].first + cost;

			if (nextCost < ans[next]) {
				ans[next] = nextCost;
				pq.push({ -nextCost, next });
			}
		}
	}

	return ans;
}

void solve() {
	input();
	answer = dijkstra();
	output();
}

int main(void) {
	solve();

	return 0;
}