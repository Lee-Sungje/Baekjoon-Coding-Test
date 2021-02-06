/* BOJ - 1697 숨바꼭질 */

#include <iostream>
#include <queue>

using namespace std;

constexpr int MAX_SIZE = 100'001;
constexpr int MOVE[] = { -1, 1, 2 };

int n, k;
bool isVisit[MAX_SIZE];
int dist[MAX_SIZE];

void bfs() {
	queue<int> q;
	q.push(n);
	isVisit[n] = true;
	dist[n] = 0;
	
	while (!q.empty()) {
		int current = q.front();
		q.pop();

		for (int d = 0; d < 3; d++) {
			int next;
			if (d == 2)	next = current * MOVE[d];
			else 		next = current + MOVE[d];

			if (0 <= next && next < MAX_SIZE) {
				if (!isVisit[next]) {
					q.push(next);
					isVisit[next] = true;
					dist[next] = dist[current] + 1;
				}
			}
		}
	}
}

void solve() {
	cin >> n >> k;
	bfs();
	cout << dist[k] << '\n';
}

int main(void) {
	solve();

	return 0;
}