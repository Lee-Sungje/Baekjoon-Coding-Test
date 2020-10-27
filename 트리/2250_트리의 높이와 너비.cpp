/* BOJ - 2250 트리의 높이와 너비 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr int TREE_SIZE = 10001;

struct Node {
	int left;
	int right;
	int depth;
	int order;
};

int n;
int order = 0;
Node tree[TREE_SIZE];
bool isNotRoot[TREE_SIZE];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int node, left, right;
		cin >> node >> left >> right;
		tree[node].left = left;
		tree[node].right = right;
		if (left != -1) isNotRoot[left] = true;
		if (right != -1) isNotRoot[right] = true;
	}
}

int getRoot() {
	for (int i = 1; i <= n; i++)
		if (!isNotRoot[i])
			return i;
}

void inorder(int node, int depth = 1) {
	if (node == -1) return;
	inorder(tree[node].left, depth + 1);
	tree[node].depth = depth;
	tree[node].order = ++order;
	inorder(tree[node].right, depth + 1);
}

void calcLavel() {
	vector<int> left(n), right(n);

	int maxDepth = 0;
	for (int node = 1; node <= n; node++) {
		int depth = tree[node].depth;
		int order = tree[node].order;

		if (maxDepth < depth) maxDepth = depth;
		left[depth] = left[depth] == 0 ? order : min(left[depth], order);
		right[depth] = right[depth] == 0 ? order : max(right[depth], order);
	}

	int depth = 0, width = 0;
	for (int d = 1; d <= maxDepth; d++) {
		if (width < right[d] - left[d] + 1) {
			depth = d;
			width = right[d] - left[d] + 1;
		}
	}
	cout << depth << ' ' << width << '\n';
}

void solve() {
	input();
	inorder(getRoot());
	calcLavel();
}

int main(void) {
	solve();

	return 0;
}