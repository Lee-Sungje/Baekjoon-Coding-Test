/* BOJ - 10972 다음 순열 */

#include <iostream>
#include <vector>

using namespace std;

bool next_permutation(vector<int> &a, int length) {
	int i;
	for (i = length - 1; i > 0; i--)
		if (a[i - 1] < a[i])
			break;
	if (length != 1 && i == 0)	return false;

	int j;
	for (j = length - 1; j > i; j--)
		if (a[i -1] < a[j])
			break;
	swap(a[i - 1], a[j]);

	for (j = length - 1; i < j; i++, j--)
		swap(a[i], a[j]);

 	return true;
}

int main(void) {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	if (next_permutation(a, n))
		for (int num : a)
			cout << num << ' ';
	else
		cout << -1 << '\n';

	return 0;
}