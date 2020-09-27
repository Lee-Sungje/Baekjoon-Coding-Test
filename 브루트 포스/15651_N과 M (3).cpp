/* BOJ - 15651 N과 M (3) */

#include <iostream>

using namespace std;

int a[8];

void recursion(int n, int m, int index = 0) {
	if (index == m) {
		for (int i = 0; i < index; i++)
			cout << a[i] << ' ';
		cout << '\n';

		return;
	}

	for (int i = 1; i <= n; i++) {
		a[index] = i;
		recursion(n, m, index + 1);
	}
}

int main(void) {
	int n, m;
	cin >> n >> m;
	recursion(n, m);

	return 0;
}