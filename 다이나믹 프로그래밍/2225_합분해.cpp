/* BOJ - 2225 합분해 */

#include <iostream>

using namespace std;

const int mod = 1'000'000'000;

int main(void) {
	int n, k;
	long long d[201][201] = { 0, };

	cin >> n >> k;
	d[0][0] = 1LL;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int l = 0; l <= j; l++) {
				d[i][j] += d[i - 1][j - l];
				d[i][j] %= mod;
			}
		}
	}
	cout << d[k][n] << '\n';

	return 0;
}