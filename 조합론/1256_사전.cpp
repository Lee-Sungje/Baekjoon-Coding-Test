/* BOJ - 1256 사전 */

#include <iostream>

using namespace std;

constexpr int MAX = 1'000'000'000;
int c[101][201];

void combination(int n, int m) {
	for (int i = 0; i <= n; i++) {
		for (int j = i; j <= n + m; j++) {
			if (i == 0 || i == j)
				c[i][j] = 1;
			else
				c[i][j] = c[i - 1][j - 1] + c[i][j - 1];

			if (c[i][j] >= MAX) c[i][j] = MAX;
		}
	}
}

void output(int n, int m, int k) {
	if (n == 0) {
		for (int i = m; i > 0; i--)
			cout << 'z';
		return;
	}

	if (m == 0) {
		for (int i = n; i > 0; i--)
			cout << 'a';
		return;
	}

	if (k <= c[n - 1][n + m - 1]) {
		cout << 'a';
		output(n - 1, m, k);
	} else {
		cout << 'z';
		output(n, m - 1, k - c[n - 1][n + m - 1]);
	}
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	combination(n, m);

	if (c[n][n + m] < k) {
		cout << -1 << '\n';
		return;
	} else {
		output(n, m, k);
	}
}

int main(void) {
	solve();

	return 0;
}