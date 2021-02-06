/* BOJ - 16940 BFS 스페셜 저지(Refactoring) */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int VERTEX_SIZE = 100'000;

int n;
vector<int> adj[VERTEX_SIZE];
vector<int> sequence;
vector<int> result;
bool isVisit[VERTEX_SIZE];

void input() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int from, to;
		cin >> from >> to;
		adj[from - 1].push_back(to - 1);
		adj[to - 1].push_back(from - 1);
	}
	sequence = vector<int>(n);
	vector<int> order(n);
	for (int i = 0; i < n; i++) {
		cin >> sequence[i];
		sequence[i] -= 1;
		order[sequence[i]] = i;
	}

	// sequence순으로 인접 리스트 정렬
	for (int i = 0; i < n; i++) {
		sort(adj[i].begin(), adj[i].end(), [&](const int &first, const int &second) {
			return order[first] < order[second];
		});
	}
}

void bfs(int start = 0) {
	queue<int> q;
	q.push(start);
	isVisit[start] = true;
	result.push_back(start);

	while (!q.empty()) {
		int current = q.front(); q.pop();
		for (int next : adj[current]) {
			if (!isVisit[next]) {
				q.push(next);
				isVisit[next] = true;
				result.push_back(next);
			}
		}
	}
}

void solve() {
	input();
	bfs();
	cout << (result == sequence) ? 1 : 0 << '\n';
}

int main(void) {
	solve();

	return 0;
}