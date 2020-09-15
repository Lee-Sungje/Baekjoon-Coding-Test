/* 백준알고리즘 - 1309 동물원 */

#include <iostream>

using namespace std;

const int mod = 9901;
int d[100'001][3];

int main(void) {
	int n;
	d[1][0] = d[1][1] = d[1][2] = 1;

	cin >> n;
	for (int i = 2; i <= n; i++) {
		d[i][0] = (d[i - 1][0] % mod) + (d[i - 1][1] % mod) + (d[i - 1][2] % mod);
		d[i][1] = (d[i - 1][0] % mod) + (d[i - 1][2] % mod);
		d[i][2] = (d[i - 1][0] % mod) + (d[i - 1][1] % mod);
	}
	cout << (d[n][0] + d[n][1] + d[n][2]) % mod << '\n';

	return 0;
}