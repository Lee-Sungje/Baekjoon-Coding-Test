/* BOJ - 10872 팩토리얼 */

#include <iostream>

using namespace std;

int Factorial(int n) {
	if (n)
		return n * Factorial(n - 1);
	else
		return 1;
}

int main(void) {
	int n;

	cin >> n;
	cout << Factorial(n) << '\n';

	return 0;
}