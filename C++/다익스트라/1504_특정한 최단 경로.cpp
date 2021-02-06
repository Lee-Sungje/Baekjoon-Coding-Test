/* BOJ - 1504 특정한 최단 경로 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> P;
constexpr int MAX_NODE = 801;
constexpr int INF = 100'000'000;

int node, edge, v1, v2;
vector<vector<P>> adj(MAX_NODE);

void input() {
	cin >> node >> edge;
	
	int from, to, dist;
	for (int i = 0; i < edge; i++) {
		cin >> from >> to >> dist;
		adj[from].push_back({ dist, to });
		adj[to].push_back({ dist, from });
	}
	cin >> v1 >> v2;
}

int dijkstra(int start, int goal) {
	vector<int> dist(node + 1, INF);
	priority_queue<P> pq;

	dist[start] = 0;
	pq.push({ 0, start });

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

	return dist[goal];
}

void solve() {
	input();
	int path1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, node);
	int path2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, node);

	int answer = min(path1, path2);
	cout << (answer < INF ? answer : -1) << '\n';
}

int main(void) {
	solve();

	return 0;
}