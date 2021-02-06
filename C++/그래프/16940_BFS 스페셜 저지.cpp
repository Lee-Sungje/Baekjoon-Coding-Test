/* BOJ - 16940 BFS 스페셜 저지 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int VERTEX_SIZE = 100'000;

int n;
vector<int> adj[VERTEX_SIZE];
vector<int> sequence;
int parent[VERTEX_SIZE];
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
	for (int i = 0; i < n; i++) {
		cin >> sequence[i];
		sequence[i] -= 1;
	}
}

bool bfs(int start = 0) {
	queue<int> q;
	q.push(start);
	isVisit[start] = true;

	int index = 1;
	for (int i = 0; i < n; i++) {
		if (q.empty()) return false;

		int current = q.front(); q.pop();
		if (current != sequence[i]) return false;

		int count = 0;
		for (int vertex : adj[current]) {
			if (!isVisit[vertex]) {
				parent[vertex] = current;
				count += 1;
			}
		}

		for (int j = 0; j < count; j++) {
			if (index + j >= n || parent[sequence[index + j]] != current)
				return false;
			q.push(sequence[index + j]);
			isVisit[sequence[index + j]] = true;
		}

		index += count;
	}
	return true;
}

void solve() {
	input();
	cout << bfs() ? 1 : 0 << '\n';
}

int main(void) {
	solve();

	return 0;
}