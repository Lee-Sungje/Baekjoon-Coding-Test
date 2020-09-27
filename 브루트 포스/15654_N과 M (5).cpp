/* BOJ - 15654 N과 M (5) */

#include <iostream>
#include <algorithm>

using namespace std;

int sequence[9];
int memory[9];
bool check[9];

void recursion(int n, int m, int index = 0) {
	if (index == m) {
		for (int i = 0; i < index; i++)
			cout << memory[i] << ' ';
		cout << '\n';

		return;
	}

	for (int i = 0; i < n; i++) {
		if (check[i])	continue;

		check[i] = true;
		memory[index] = sequence[i];
		recursion(n, m, index + 1);
		check[i] = false;
	}
}

int main(void) {
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		cin >> sequence[i];

	sort(sequence, sequence + n);
	recursion(n, m);

	return 0;
}