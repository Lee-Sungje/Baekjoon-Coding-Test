/* 백준알고리즘 - 11057 오르막 수 */

#include <iostream>

using namespace std;

const int mod = 10'007;
int d[1001][10] = { {}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };

int main(void) {
	int n;

	cin >> n;
	for (int i = 2; i <= n; i++) {
		d[i][0] = 1;
		for (int j = 1; j <= 9; j++)
			d[i][j] = d[i][j - 1] + d[i - 1][j] % mod;
	}

	int result = 0;
	for (int i = 0; i <= 9; i++)
		result += d[n][i];
	cout << result % mod << '\n';

	return 0;
}