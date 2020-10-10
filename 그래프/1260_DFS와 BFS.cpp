/* BOJ - 1260 DFS와 BFS */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int vertex_size = 1001;

int n, m, v;
vector<int> list[vertex_size];
bool visit_dfs[vertex_size];
bool visit_bfs[vertex_size];

void input() {
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;

		list[from].push_back(to);
		list[to].push_back(from);
	}

	for (int i = 0; i < n; i++)
		sort(list[i].begin(), list[i].end());
}

void dfs(int v) {
	cout << v << ' ';
	visit_dfs[v] = true;
	for (int i = 0; i < list[v].size(); i++) {
		if (!visit_dfs[list[v][i]])
			dfs(list[v][i]);
	}
}

void bfs(int v) {
	queue<int> q;

	visit_bfs[v] = true;
	q.push(v);
	while (!q.empty()) {
		int front = q.front();
		cout << front << ' ';
		q.pop();
		for (int i = 0; i < list[front].size(); i++) {
			if (!visit_bfs[list[front][i]]) {
				visit_bfs[list[front][i]] = true;
				q.push(list[front][i]);
			}
		}
	}
}

void solve() {
	input();

	dfs(v);
	cout << '\n';
	bfs(v);
}

int main(void) {
	solve();

	return 0;
}