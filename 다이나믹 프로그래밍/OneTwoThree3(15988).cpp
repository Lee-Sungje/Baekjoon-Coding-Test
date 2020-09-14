/* 백준알고리즘 - 15988 1, 2, 3 더하기 3 */

#include <iostream>

using namespace std;

const int mod = 1'000'000'009;
unsigned int d[1'000'001] = { 1, 1, 2, };

int addition(int n) {
	if(!d[n])
		d[n] = addition(n - 1) + addition(n - 2) + addition(n - 3);

	return d[n] % mod;
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