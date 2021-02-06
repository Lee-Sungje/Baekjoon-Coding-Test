/* BOJ - 10973 이전 수열 */

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

	if (prev_permutation(a.begin(), a.end()))
		for (int element : a)
			cout << element << ' ';
	else
		cout << -1 << '\n';

	return 0;
}