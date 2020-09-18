/* 백준알고리즘 - 1932 정수 삼각형 */

#include <iostream>
#include <algorithm>

using namespace std;

int t[501][501];
int d[501][501];

int main(void) {
	int n;

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> t[i][j];

	for (int i = n; i > 0; i--) {
		for (int j = i; j > 0; j--) {
			if (i == n)
				d[i][j] = t[i][j];
			else
				d[i][j] = t[i][j] + max(d[i + 1][j], d[i + 1][j + 1]);
		}
	}
	cout << d[1][1] << '\n';

	return 0;
}