/* BOJ - 1068 트리 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr int MAX_NODE = 50;

int n, root, reaf, removeNode;
vector<int> tree[MAX_NODE];

void input() {
	cin >> n;
	for (int node = 0; node < n; node++) {
		int parent;
		cin >> parent;
		if (parent == -1)
			root = node;
		else
			tree[parent].push_back(node);
	}
	cin >> removeNode;
}

void dfs(int start) {
	if (start == removeNode) return;
	if (tree[start].empty()) {
		reaf += 1;
		return;
	}
	for (int node : tree[start]) {
		dfs(node);
		if (node == removeNode && tree[start].size() == 1)
			reaf += 1;
	}
}

void solve() {
	input();
	dfs(root);
	cout << reaf << '\n';
}

int main(void) {
	solve();

	return 0;
}