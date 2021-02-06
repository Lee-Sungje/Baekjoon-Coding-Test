/* BOJ - 1167 트리의 지름 */

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr int VERTEX_SIZE = 100'001;

struct Edge {
	int to;
	int cost;

	Edge(int _to, int _cost) : to(_to), cost(_cost) {}
};

int v;
int dist[VERTEX_SIZE];
vector<Edge> graph[VERTEX_SIZE];

void input() {
	cin >> v;

	for (int i = 0; i < v; i++) {
		int vertex;
		cin >> vertex;
		while (true) {
			int to, cost;
			cin >> to;
			if (to == -1) break;
			cin >> cost;
			graph[vertex].push_back(Edge(to, cost));
		}
	}
}

int getMaxIndex() {
	int index = 1, maximum = dist[1];
	for (int i = 2; i <= v; i++) {
		if (maximum < dist[i]) {
			maximum = dist[i];
			index = i;
		}
	}
	return index;
}

void bfs(int start = 1) {
	memset(dist, -1, sizeof(dist));

	queue<int> q;
	q.push(start);
	dist[start] = 0;

	while (!q.empty()) {
		int vertex = q.front(); q.pop();

		for (int i = 0; i < graph[vertex].size(); i++) {
			int next = graph[vertex][i].to;
			if (dist[next] == -1) {
				dist[next] = dist[vertex] + graph[vertex][i].cost;
				q.push(next);
			}
		}
	}
}

void solve() {
	input();
	bfs();
	bfs(getMaxIndex());
	cout << dist[getMaxIndex()] << '\n';
}

int main(void) {
	solve();

	return 0;
}