/* BOJ - 1707 이분 그래프 */

#include <cstdio>
#include <array>
#include <vector>

using namespace std;

constexpr int VERTEX_SIZE = 20'001;

int v, e;
vector<int> adjacencyList[VERTEX_SIZE];
array<int, VERTEX_SIZE> isGroup; // 0: No Group, 1: Group1, 2: Group2

void init() {
	for (int i = 1; i <= v; i++)
		adjacencyList[i].clear();
	isGroup.fill(0);
}

void input() {
	scanf_s("%d %d", &v, &e);

	for (int i = 0; i < e; i++) {
		int from, to;
		scanf_s("%d %d", &from, &to);
		adjacencyList[from].push_back(to);
		adjacencyList[to].push_back(from);
	}
}

bool check() {
	for (int i = 1; i <= v; i++) {
		for (int j = 0; j < adjacencyList[i].size(); j++) {
			int now = adjacencyList[i][j];
			if (isGroup[i] == isGroup[now])
				return false;
		}
	}
	return true;
}

void dfs(int node, int group) {
	isGroup[node] = group;
	for (int i = 0; i < adjacencyList[node].size(); i++) {
		int next = adjacencyList[node][i];
		if (isGroup[next] == 0)
			dfs(next, 3 - group);
	}
}

void solve() {
	int testcase;
	scanf_s("%d\n", &testcase);
	while (testcase--) {
		init();
		input();
		
		for (int i = 1; i <= v; i++)
			if (isGroup[i] == 0)
				dfs(i, 1);

		bool answer = check();
		printf("%s\n", answer ? "YES" : "NO");
	}
}

int main(void) {
	solve();

	return 0;
}