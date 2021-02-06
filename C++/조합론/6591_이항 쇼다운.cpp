/* BOJ 6591 - 이항 쇼다운 */

#include <algorithm>
#include <iostream>

using namespace std;

void solve() {
	while (true) {
		long long answer = 1;
		int n, r;
		cin >> n >> r;

		if (n == 0 && r == 0) break;

		r = min(r, n - r);

		for (int i = 1; i <= r; i++) {
			answer *= n;
			answer /= i;
			n -= 1;
		}
		cout << answer << '\n';
	}
}

int main(void) {
	solve();

	return 0;
}