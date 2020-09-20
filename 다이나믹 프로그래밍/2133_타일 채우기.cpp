/* BOJ - 2133 타일 채우기 */

#include <iostream>

using namespace std;

int d[31] = { 1 };

int main(void) {
	int n;

	cin >> n;
	if (n % 2)
		d[n] = 0;
	else {
		for (int i = 2; i <= n; i += 2) {
			d[i] = d[i - 2] * 3;
			for (int j = i - 2; j > 0; j -= 2)
				d[i] += d[j - 2] * 2;
		}
	}
	cout << d[n] << '\n';

	return 0;
}