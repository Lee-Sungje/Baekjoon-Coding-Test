/* 백준알고리즘 - 11722 가장 긴 감소하는 부분 수열 */

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
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[i] < a[j] && d[i] < d[j] + 1)
				d[i] = d[j] + 1;
		}
	}
	cout << *max_element(d, d + n) << '\n';

	return 0;
}