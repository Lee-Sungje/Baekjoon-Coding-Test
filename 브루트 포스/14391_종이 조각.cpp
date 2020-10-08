/* BOJ - 14391 종이 조각 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int a[4][4];
int answer = 0;

void solve() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf_s("%1d", &a[i][j]);

	for (int bitmask = 0; bitmask < (1 << (n * m)); bitmask++) {
		int sum = 0;

		for (int i = 0; i < n; i++) {
			int row = 0;

			for (int j = 0; j < m; j++) {
				int k = i * m + j;

				if ((bitmask & (1 << k)) == 0) {
					row = row * 10 + a[i][j];
				} else {
					sum += row;
					row = 0;
				}
			}
			sum += row;
		}

		for (int j = 0; j < m; j++) {
			int column = 0;

			for (int i = 0; i < n; i++) {
				int k = i * m + j;

				if ((bitmask & (1 << k)) != 0) {
					column = column * 10 + a[i][j];
				} else {
					sum += column;
					column = 0;
				}
			}
			sum += column;
		}
		
		answer = max(answer, sum);
	}
	cout << answer << '\n';
}

int main(void) {
	solve();

	return 0;
}