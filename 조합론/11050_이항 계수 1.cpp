/* BOJ - 11050 이항 계수 1 */

#include <iostream>

using namespace std;

int dp[11][11];

int combination(int n, int k) {
	if (k == 0 || k == n) return dp[k][n] = 1;

	if (dp[k][n] == 0)
		dp[k][n] = combination(n - 1, k - 1) + combination(n - 1, k);

	return dp[k][n];
}

void solve() {
	int n, k;
	cin >> n >> k;
	cout << combination(n, k) << '\n';
}

int main(void) {
	solve();

	return 0;
}