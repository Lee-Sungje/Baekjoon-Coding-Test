/* BOJ - 1991 트리 순회 */

#include <iostream>

using namespace std;

constexpr int TREE_SIZE = 26;
constexpr int ROOT = 0;

struct Node {
	int left;
	int right;
};

int n;
Node tree[TREE_SIZE];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char p, l, r;
		cin >> p >> l >> r;
		tree[p - 'A'].left = l - 'A';
		tree[p - 'A'].right = r - 'A';
	}
}

void preorder(int x) {
	if (x == '.' - 'A') return;
	cout << (char)('A' + x);
	preorder(tree[x].left);
	preorder(tree[x].right);
}

void inorder(int x) {
	if (x == '.' - 'A') return;
	inorder(tree[x].left);
	cout << (char)('A' + x);
	inorder(tree[x].right);
}

void postorder(int x) {
	if (x == '.' - 'A') return;
	postorder(tree[x].left);
	postorder(tree[x].right);
	cout << (char)('A' + x);
}

void solve() {
	input();
	preorder(ROOT);		cout << '\n';
	inorder(ROOT);		cout << '\n';
	postorder(ROOT);	cout << '\n';
}

int main(void) {
	solve();

	return 0;
}