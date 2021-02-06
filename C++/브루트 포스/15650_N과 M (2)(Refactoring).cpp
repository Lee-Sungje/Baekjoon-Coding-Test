/* BOJ - 15650 N과 M (2)(Refactoring) */

#include <iostream>

using namespace std;

int a[10];

void recursion(int n, int m, int index = 1, int selected = 0) {
	if (selected == m) {
		for (int i = 0; i < selected; i++)
			cout << a[i] << ' ';
		cout << '\n';

		return;
	}

	if (index > n)	return;

	a[selected] = index;
	recursion(n, m, index + 1, selected + 1);
	a[selected] = 0;
	recursion(n, m, index + 1, selected);	
}

int main(void) {
	int n, m;
	cin >> n >> m;
	recursion(n, m);

	return 0;
}