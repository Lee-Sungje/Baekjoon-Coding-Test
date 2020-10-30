/* BOJ - 2606 바이러스 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int COMPUTER_SIZE = 100;

int node, edge;
vector<int> computer[COMPUTER_SIZE];
bool isVisit[COMPUTER_SIZE];

void input() {
	cin >> node;
	cin >> edge;
	for (int n = 0; n < edge; n++) {
		int from, to;
		cin >> from >> to;
		computer[from - 1].push_back(to - 1);
		computer[to - 1].push_back(from - 1);
	}
}

int bfs(int start) {
	queue<int> q;
	q.push(start);
	isVisit[start] = true;

	int answer = 0;
	while (!q.empty()) {
		int current = q.front();
		q.pop();

		for (int n : computer[current]) {
			if (!isVisit[n]) {
				q.push(n);
				isVisit[n] = true;
				answer += 1;
			}
		}
	}

	return answer;
}

void solve() {
	input();
	cout << bfs(0) << '\n';
}

int main(void) {
	solve();

	return 0;
}