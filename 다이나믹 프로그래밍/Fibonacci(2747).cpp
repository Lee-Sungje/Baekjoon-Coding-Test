/* 백준알고리즘 - 2747 피보나치 수 */

#include <iostream>

using namespace std;

const int memory_size = 45;
int memo[memory_size] = { 0, };

int fibonacci(int n) {
	if (n <= 1) {
		return n;
	} else {
		if(!memo[n])
			memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
		return memo[n];
	}
}

int main(void) {
	int n;

	cin >> n;
	cout << fibonacci(n) << '\n';

	return 0;
}