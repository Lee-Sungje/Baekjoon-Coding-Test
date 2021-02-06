/* BOJ - 2644 촌수계산 */

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr int MAX_SIZE = 101;

int n, m, from, to;
vector<int> familyTree[MAX_SIZE];
int dist[MAX_SIZE];

void input() {
	cin >> n;
	cin >> from >> to;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int parent, child;
		cin >> parent >> child;
		familyTree[parent].push_back(child);
		familyTree[child].push_back(parent);
	}
}

void bfs() {
	queue<int> q;
	q.push(from);
	dist[from] = 0;

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		for (int i = 0; i < familyTree[current].size(); i++) {
			int next = familyTree[current][i];
			if (dist[next] == -1) {
				q.push(next);
				dist[next] = dist[current] + 1;
			}
		}
	}
}

void solve() {
	input();
	memset(dist, -1, sizeof(dist));
	bfs();
	cout << dist[to] << '\n';
}

int main(void) {
	solve();

	return 0;
}