/* BOJ - 13913 숨바꼭질 4 */

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

constexpr int MAX_SIZE = 100'001;
constexpr int MOVE[] = { -1, 1, 2 };

int n, k;
bool isVisit[MAX_SIZE];
int dist[MAX_SIZE];
int from[MAX_SIZE];
stack<int> route;

void trace() {
	route.push(k);
	int previous = from[k];
	while (previous != -1) {
		route.push(previous);
		previous = from[previous];
	}
}

void print() {
	cout << dist[k] << '\n';
	while (!route.empty()) {
		cout << route.top() << ' ';
		route.pop();
	}
	cout << '\n';
}

void bfs() {
	queue<int> q;
	q.push(n);
	isVisit[n] = true;
	dist[n] = 0;
	from[n] = -1;

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		for (int m = 0; m < 3; m++) {
			int next;
			if (m == 2) next = current * MOVE[m];
			else		next = current + MOVE[m];

			if (0 <= next && next < MAX_SIZE) {
				if (!isVisit[next]) {
					q.push(next);
					isVisit[next] = true;
					dist[next] = dist[current] + 1;
					from[next] = current;
				}
			}
		}
	}
}

void solve() {
	cin >> n >> k;
	bfs();
	trace();
	print();
}

int main(void) {
	solve();

	return 0;
}