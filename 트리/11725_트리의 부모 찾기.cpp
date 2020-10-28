/* BOJ - 11725 트리의 부모 찾기 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr int MAX_SIZE = 100'001;
constexpr int ROOT = 1;

int n;
vector<int> adj[MAX_SIZE];
int parent[MAX_SIZE];

void input() {
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int from, to;
		cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
}

void output() {
	for (int i = 2; i <= n; i++)
		cout << parent[i] << '\n';
}

void bfs(int root) {
	queue<int> q;
	q.push(root);
	parent[root] = -1;

	while (!q.empty()) {
		int node = q.front(); q.pop();

		for (int i = 0; i < adj[node].size(); i++) {
			int nextNode = adj[node][i];

			if (parent[nextNode] == 0) {
				q.push(nextNode);
				parent[nextNode] = node;
			}
		}
	}
}

void solve() {
	input();
	bfs(ROOT);
	output();
}

int main(void) {
	solve();

	return 0;
}