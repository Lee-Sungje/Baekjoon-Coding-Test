/* BOJ - 1238 파티 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> P;

constexpr int MAX_VERTEX = 1'001;
constexpr int INF = 100'000'000;

int vertex, edge, goal;
vector<vector<P>> graph, directGraph(MAX_VERTEX), reverseGraph(MAX_VERTEX);
vector<int> answers[2];

void input() {
	cin >> vertex >> edge >> goal;

	int from, to, cost;
	for (int i = 0; i < edge; i++) {
		cin >> from >> to >> cost;
		directGraph[from].push_back({ cost, to });
		reverseGraph[to].push_back({ cost, from });
	}
}

vector<int> dijkstra(int direction) {
	vector<int> cost(vertex + 1, INF);
	priority_queue<P> pq;
	
	graph = (direction == 0) ? directGraph : reverseGraph;
	pq.push({ 0, goal });
	cost[goal] = 0;

	while (!pq.empty()) {
		int current = pq.top().second;
		int currentCost = -pq.top().first;
		pq.pop();

		if (cost[current] < currentCost) continue;

		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i].second;
			int nextCost = graph[current][i].first + currentCost;

			if (nextCost < cost[next]) {
				cost[next] = nextCost;
				pq.push({ -nextCost, next });
			}
		}
	}

	return cost;
}

void solve() {
	input();
	for (int i = 0; i < 2; i++)
		answers[i] = dijkstra(i);

	int answer = 0;
	for (int i = 1; i <= vertex; i++)
		answer = max(answer, answers[0][i] + answers[1][i]);

	cout << answer << '\n';
}

int main(void) {
	solve();

	return 0;
}