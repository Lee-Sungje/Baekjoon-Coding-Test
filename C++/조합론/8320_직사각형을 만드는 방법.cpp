/* BOJ - 8320 직사각형을 만드는 방법 */

#include <cmath>
#include <iostream>

using namespace std;

void solve() {
	int n, range;
	cin >> n;

	range = (int)sqrt(n);
	int answer = 0;
	for (int i = 1; i <= range; i++)
		answer += (n - (int)pow(i, 2)) / i + 1;

	cout << answer << '\n';
}

int main(void) {
	solve();

	return 0;
}