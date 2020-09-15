/* 백준알고리즘 - 1149 RGB 거리 */

#include <iostream>
#include <algorithm>

using namespace std;

const int r = 0;
const int g = 1;
const int b = 2;

int a[1001][3];
int d[1001][3];

int main(void) {
	int n;

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i][r] >> a[i][g] >> a[i][b];

	for (int i = 1; i <= n; i++) {
		d[i][r] = min(d[i - 1][g], d[i - 1][b]) + a[i][r];
		d[i][g] = min(d[i - 1][r], d[i - 1][b]) + a[i][g];
		d[i][b] = min(d[i - 1][r], d[i - 1][g]) + a[i][b];
	}
	cout << min(d[n][r], min(d[n][g], d[n][b])) << '\n';

	return 0;
}