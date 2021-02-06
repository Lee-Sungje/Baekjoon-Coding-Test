/* BOJ - 10282 해킹 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> P;
constexpr int INF = 100'000'000;

vector<vector<P>> input(const int node, const int vertex) {
	vector<vector<P>> adjacencyList(node + 1);

	for (int i = 0; i < vertex; i++) {
		int from, to, cost;
		cin >> to >> from >> cost;

		adjacencyList[from].push_back({ cost, to });
	}

	return adjacencyList;
}

vector<int> dijkstra(vector<vector<P>>& adj, const int start) {
	priority_queue<P> pq;
	vector<int> dist(adj.size(), INF);

	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int current = pq.top().second;
		int currentCost = -pq.top().first;
		pq.pop();

		if (dist[current] < currentCost) continue;

		for (int i = 0; i < adj[current].size(); i++) {
			int next = adj[current][i].second;
			int nextCost = adj[current][i].first + currentCost;

			if (nextCost < dist[next]) {
				dist[next] = nextCost;
				pq.push({ -nextCost, next });
			}
		}
	}

	return dist;
}

void solve() {
	int testcase;
	cin >> testcase;

	while (testcase--) {
		int node, vertex, infection;
		cin >> node >> vertex >> infection;

		auto adj = input(node, vertex);
		auto dist = dijkstra(adj, infection);

		int cnt = 0, time = 0;
		for (int i = 1; i < dist.size(); i++) {
			if (dist[i] != INF) {
				cnt += 1;
				if (time < dist[i])
					time = dist[i];
			}
		}
		cout << cnt << ' ' << time << '\n';
	}
}

int main() {
	solve();

	return 0;
}