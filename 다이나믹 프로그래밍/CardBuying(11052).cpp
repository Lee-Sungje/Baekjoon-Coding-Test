/* 백준알고리즘 - 11052 카드 구매하기 */

#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1001;

int main(void) {
	int n;
	int d[max_n] = { 0, };
	int p[max_n] = { 0, };

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = max(d[i], d[i - j] + p[j]);
		}
	}
	cout << d[n] << '\n';

	return 0;
}