/* BOJ - 13023 ABCDE(Refactoring) */

#include <iostream>
#include <vector>

using namespace std;

vector<int> list[2000];
bool visit[2000];
bool answer;

void dfs(int index, int count) {
	if (count == 5) {
		answer = true;
		return;
	}

	visit[index] = true;
	for (int i = 0; i < list[index].size(); i++) {
		if (visit[list[index][i]])	continue;
		dfs(list[index][i], count + 1);
		if (answer)	return;
	}
	visit[index] = false;
}

void solve() {
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;

		list[from].push_back(to);
		list[to].push_back(from);
	}

	for (int i = 0; i < m; i++) {
		dfs(i, 1);
		if (answer) break;
	}
	cout << answer << '\n';
}

int main(void) {
	solve();

	return 0;
}