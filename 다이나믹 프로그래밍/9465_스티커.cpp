/* BOJ - 9465 스티커 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[2][100'001];
int d[3][100'001];

int main(void) {
	int t;

	cin >> t;
	while (t--) {
		int n;
		
		cin >> n;
		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= n; j++)
				scanf_s("%d", &a[i][j]);	//cin >> a[i][j];

		for (int i = 1; i <= n; i++) {
			d[0][i] = max({ d[0][i - 1], d[1][i - 1], d[2][i - 1] });
			d[1][i] = max(d[0][i - 1], d[2][i - 1]) + a[0][i];
			d[2][i] = max(d[0][i - 1], d[1][i - 1]) + a[1][i];
		}
		cout << max({ d[0][n], d[1][n], d[2][n] }) << '\n';
	}

	return 0;
}