/* 백준알고리즘 - 2193 이친수 */

#include <iostream>

using namespace std;

const int max_n = 91;
long long d[max_n] = { 0, };

long long IChinSoo(int n) {
	if (n <= 2)
		return 1;
	else {
		if (!d[n])
			d[n] = IChinSoo(n - 1) + IChinSoo(n - 2);
		return d[n];
	}
}

int main(void) {
	int n;

	cin >> n;
	cout << IChinSoo(n);

	return 0;
}