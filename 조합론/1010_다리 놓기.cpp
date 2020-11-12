/* BOJ - 1010 다리 놓기 */

#include <algorithm>
#include <iostream>

using namespace std;

typedef unsigned long long ULL;

ULL answers[31][31];

ULL dp(int n, int r) {
	if (r == 0 || r == n) return answers[r][n] = 1;

	if (answers[r][n] == 0)
		answers[r][n] = dp(n - 1, r - 1) + dp(n - 1, r);

	return answers[r][n];
}

void solve() {
	int testcase;
	cin >> testcase;

	while (testcase--) {
		int n, m;
		cin >> n >> m;
		cout << dp(m, n) << '\n';
	}
}

int main(void) {
	solve();

	return 0;
}