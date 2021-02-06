/* BOJ - 1325 효율적인 해킹 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr int NODE_SIZE = 10'001;

int node_length, vertex_length;
vector<vector<int>> adj(NODE_SIZE);
vector<int> memory(NODE_SIZE);

void input() {
	cin >> node_length >> vertex_length;

	for (int i = 0; i < vertex_length; i++) {
		int from, to;
		cin >> to >> from;

		adj[from].push_back(to);
	}
}

int bfs(int start) {
	int node_count = 0;
	queue<int> q;
	vector<bool> visit(node_length + 1, false);

	q.push(start);
	visit[start] = true;
	while (!q.empty()) {
		int current_node = q.front();
		q.pop();

		for (int next_node : adj[current_node]) {
			if (!visit[next_node]) {
				node_count += 1;
				q.push(next_node);
				visit[next_node] = true;
			}
		}
	}

	return node_count;
}

void solve() {
	input();

	int max = 0;
	for (int node = 1; node <= node_length; node++) {
		memory[node] = bfs(node);
		max = max < memory[node] ? memory[node] : max;
	}

	for (int node = 1; node <= node_length; node++) {
		if (memory[node] == max)
			cout << node << ' ';
	}
}

int main(void) {
	solve();

	return 0;
}