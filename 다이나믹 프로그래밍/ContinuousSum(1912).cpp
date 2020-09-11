/* 백준알고리즘 - 1912 연속합 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<int> d = a;
	for (int i = 1; i < n; i++)
		if (d[i] < d[i] + d[i - 1])
			d[i] += d[i - 1];

	cout << *max_element(d.begin(), d.end()) << '\n';

	return 0;
}