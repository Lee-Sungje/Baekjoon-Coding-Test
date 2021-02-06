/* BOJ - 10451 순열 사이클 */

#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

constexpr int VERTEX_SIZE = 1001;

int n;
int permutation[VERTEX_SIZE];
bool isVisit[VERTEX_SIZE];

void init() {
	memset(permutation, 0, sizeof(permutation));
	memset(isVisit, false, sizeof(isVisit));
}

void input() {
	cin >> n;
	for (int from = 1; from <= n; from++) {
		int to;
		cin >> to;
		permutation[from] = to;
	}
}

void bfs(int v) {
	queue<int> q;
	q.push(v);
	isVisit[v] = true;

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		
		if (!isVisit[permutation[current]]) {
			q.push(permutation[current]);
			isVisit[permutation[current]] = true;
		}
	}
}

void solve() {
	int testcase;
	cin >> testcase;

	while (testcase--) {
		init();
		input();

		int cycle = 0;
		for (int v = 1; v <= n; v++) {
			if (!isVisit[v]) {
				bfs(v);
				cycle += 1;
			}
		}
		cout << cycle << '\n';
	}
}

int main(void) {
	solve();

	return 0;
}