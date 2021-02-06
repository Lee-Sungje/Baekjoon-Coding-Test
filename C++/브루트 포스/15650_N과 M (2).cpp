/* BOJ - 15650 N과 M (2) */

#include <iostream>

using namespace std;

bool check[9];
int a[9];

void recursion(int n, int m, int index = 0, int start = 1) {
	if (index == m) {
		for (int i = 0; i < index; i++)
			cout << a[i] << ' ';
		cout << '\n';

		return;
	}

	for (int i = start; i <= n; i++) {
		if (check[i])	continue;
		check[i] = true;
		a[index] = i;
		recursion(n, m, index + 1, i + 1);
		check[i] = false;
	}
}

int main(void) {
	int n, m;
	cin >> n >> m;
	recursion(n, m);

	return 0;
}