/* BOJ - 6064 카잉 달력 */

#include <iostream>

using namespace std;

int main(void) {
	int t;
	int m, n, x, y;

	cin >> t;
	while (t--) {
		cin >> m >> n >> x >> y;

		bool is_valid = false;
		x -= 1;
		y -= 1;
		for (int k = x; k < (m*n); k += m) {
			if (k % n == y) {
				cout << k + 1 << '\n';
				is_valid = true;
				break;
			}
		}
		if (!is_valid)
			cout << -1 << '\n';
	}

	return 0;
}