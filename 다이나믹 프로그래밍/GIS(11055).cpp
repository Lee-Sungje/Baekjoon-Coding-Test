/* 백준알고리즘 - 11055 가장 큰 증가하는 부분 수열 */

#include <iostream>
#include <algorithm>

using namespace std;

int a[1000];
int d[1000];

int main(void) {
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];

		d[i] = a[i];
		for (int j = 0; j < i; j++)
			if (a[j] < a[i] && d[i] < d[j] + a[i])
				d[i] = d[j] + a[i];
	}
	cout << *max_element(d, d + n) << '\n';

	return 0;
}