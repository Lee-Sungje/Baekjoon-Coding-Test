/* BOJ - 9095 1, 2, 3 더하기 */

#include <iostream>

using namespace std;

const int memory_size = 12;
int memory[memory_size] = { 0, };

int addition(int n) {
	if (n == 1) { return 1; }
	else if (n == 2) { return 2; }
	else if (n == 3) { return 4; }
	else {
		if (memory[n]) return memory[n];
		memory[n] = addition(n - 1) + addition(n - 2) + addition(n - 3);
	}

	return memory[n];
}

int main(void) {
	int t;

	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << addition(n) << '\n';
	}

	return 0;
}