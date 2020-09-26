/* BOJ - 15649 N과 M (1) */

#include <iostream>

using namespace std;

bool check[9];
int a[9];

void recursion(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < index; i++)
			cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		if (check[i] == true)	continue;
		check[i] = true;
		a[index] = i;
		recursion(index + 1, n, m);
		check[i] = false;
	}
}

int main(void) {
	int n, m;
	cin >> n >> m;
	recursion(0, n, m);

	return 0;
}