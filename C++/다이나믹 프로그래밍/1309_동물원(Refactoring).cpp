/* BOJ - 1309 동물원(Refactoring) */

#include <iostream>

using namespace std;

const int mod = 9901;
int d[100'001] = { 1, 2 };
int s[100'001] = { 1, 3 };

int main(void) {
	int n;

	cin >> n;
	for (int i = 2; i <= n; i++) {
		d[i] = (d[i - 1] + 2 * s[i - 2]) % mod;
		s[i] = (d[i] + s[i - 1]) % mod;
	}
	cout << s[n] << '\n';

	return 0;
}