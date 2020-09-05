/* 백준알고리즘 - 1929 소수 구하기 */

#include <iostream>
#include <vector>

using namespace std;

vector<bool> SieveOfEratosthenes(int n) {
	vector<bool> prime(n + 1, true);

	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= n; i++)
		for (int j = i * i; j <= n; j += i)
			prime[j] = false;

	return prime;
}

int main(void) {
	int m, n;

	cin >> m >> n;
	vector<bool> prime = SieveOfEratosthenes(n);

	for (int idx = m; idx <= n; idx++)
		if (prime[idx])
			cout << idx << '\n';

	return 0;
}