/* BOJ - 17404 RGB거리 2 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int r = 0;
const int g = 1;
const int b = 2;
const int maxVal = 1000 * 1000 + 1;

int a[3][1001];
int d[3][1001];

int main(void) {
	int n;

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf_s("%d %d %d", &a[r][i], &a[g][i], &a[b][i]);

	int ans = maxVal;
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < 3; i++) {
			if (i == k)
				d[i][1] = a[i][1];
			else
				d[i][1] = maxVal;
		}

		for (int i = 2; i <= n; i++) {
			d[r][i] = min(d[g][i - 1], d[b][i - 1]) + a[r][i];
			d[g][i] = min(d[r][i - 1], d[b][i - 1]) + a[g][i];
			d[b][i] = min(d[r][i - 1], d[g][i - 1]) + a[b][i];
		}

		for (int i = 0; i < 3; i++) {
			if (i == k)		continue;
			ans = min(ans, d[i][n]);
		}
	}
	cout << ans << '\n';

	return 0;
}