/* BOJ - 2225 합분해(Refactoring) */

#include <iostream>

using namespace std;

const int mod = 1'000'000'000;
int d[201][201];

int main(void) {
	int n, k;

	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		d[i][1] = i;
		for (int j = 2; j <= n; j++)
			d[i][j] = (d[i][j - 1] + d[i - 1][j]) % mod;
	}
	cout << d[k][n] << '\n';

	return 0;
}