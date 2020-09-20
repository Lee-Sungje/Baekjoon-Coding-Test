﻿/* BOJ - 13398 연속합 2 */

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n;

	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		d[i] = a[i];
		if (i == 0)		continue;
		if (a[i] < d[i - 1] + a[i])
			d[i] = d[i - 1] + a[i];
	}

	vector<int> dr(n);
	for (int i = n - 1; i >= 0; i--) {
		dr[i] = a[i];
		if (i == n - 1)	continue;
		if (a[i] < dr[i + 1] + a[i])
			dr[i] = dr[i + 1] + a[i];
	}

	int ans = d[0];
	for (int i = 1; i < n; i++)
		if (ans < d[i])
			ans = d[i];

	for (int i = 1; i < n - 1; i++)
		if (ans < d[i - 1] + dr[i + 1])
			ans = d[i - 1] + dr[i + 1];

	cout << ans << '\n';

	return 0;
}