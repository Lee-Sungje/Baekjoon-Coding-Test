/* BOJ - 10974 모든 순열 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	vector<int> a;
	for (int i = 1; i <= n; i++)
		a.push_back(i);

	do {
		for (int element : a)
			cout << element << ' ';
		cout << '\n';
	} while (next_permutation(a.begin(), a.end()));

	return 0;
}