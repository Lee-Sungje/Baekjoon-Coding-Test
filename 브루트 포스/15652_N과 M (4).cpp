/* BOJ - 15652 N과 M (4) */

#include <iostream>

using namespace std;

int a[9];

void recursion(int n, int m, int index = 0, int start = 1) {
	if (index == m) {
		for (int i = 0; i < index; i++)
			cout << a[i] << ' ';
		cout << '\n';

		return;
	}

	for (int i = start; i <= n; i++) {
		a[index] = i;
		recursion(n, m, index + 1, i);
	}
}

int main(void) {
	int n, m;
	cin >> n >> m;
	recursion(n, m);

	return 0;
}