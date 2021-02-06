/* BOJ - 13023 ABCDE */

#include <iostream>
#include <vector>

using namespace std;

bool matrix[2000][2000];		// 인접행렬
vector<int> list[2000];			// 인접리스트
vector<pair<int, int>> edges;	// 간선리스트

void solve() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;

		matrix[from][to] = matrix[to][from] = true;

		edges.push_back({ from, to });
		edges.push_back({ to, from });

		list[from].push_back(to);
		list[to].push_back(from);
	}

	m *= 2;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			// A -> B
			int A = edges[i].first;
			int B = edges[i].second;
			// C -> D
			int C = edges[j].first;
			int D = edges[j].second;
			if (A == B || A == C || A == D || B == C || B == D || C == D)
				continue;
			// B -> C
			if (!matrix[B][C])
				continue;
			// D -> E
			for (int E : list[D]) {
				if (A == E || B == E || C == E || D == E)
					continue;
				cout << 1 << '\n';
				return;
			}
		}
	}
	cout << 0 << '\n';
}

int main(void) {
	solve();

	return 0;
}