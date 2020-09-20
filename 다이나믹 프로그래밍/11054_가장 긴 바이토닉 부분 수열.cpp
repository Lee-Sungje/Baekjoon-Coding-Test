/* BOJ - 11054 가장 긴 바이토닉 부분 수열 */

#include <iostream>
#include <algorithm>

using namespace std;

int a[1000];
int d[2][1000];
int sum[1000];

int main(void) {
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++) {
		d[0][i] = 1;
		for (int j = 0; j < i; j++)
			if (a[j] < a[i] && d[0][i] < d[0][j] + 1)
				d[0][i] = d[0][j] + 1;
	}

	for (int i = n - 1; i >= 0; i--) {
		d[1][i] = 1;
		for (int j = n - 1; j >= i; j--) {
			if (a[j] < a[i] && d[1][i] < d[1][j] + 1)
				d[1][i] = d[1][j] + 1;
		}
	}

	for (int i = 0; i < n; i++)
		sum[i] = d[0][i] + d[1][i];

	int result = *max_element(sum, sum + n) - 1;
	cout << result << '\n';

	return 0;
}