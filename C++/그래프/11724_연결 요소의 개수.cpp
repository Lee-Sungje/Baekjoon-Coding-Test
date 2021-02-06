/* BOJ - 11724 연결 요소의 개수 */

#include <iostream>
#include <vector>

using namespace std;

constexpr int VERTEX_SIZE = 1001;

int n, m;
vector<int> adjacencyList[VERTEX_SIZE];
bool isVisit[VERTEX_SIZE];

void dfs(int vertex) {
	for (int i = 0; i < adjacencyList[vertex].size(); i++) {
		int v = adjacencyList[vertex][i];
		if (isVisit[v]) continue;
		isVisit[v] = true;
		dfs(v);
	}
}

void input() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int from, to;
		cin >> from >> to;
		adjacencyList[from].push_back(to);
		adjacencyList[to].push_back(from);
	}
}

void solve() {
	input();

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		if (isVisit[i])	continue;
		answer += 1;
		isVisit[i] = true;
		dfs(i);
	}
	cout << answer << '\n';
}

int main(void) {
	solve();

	return 0;
}