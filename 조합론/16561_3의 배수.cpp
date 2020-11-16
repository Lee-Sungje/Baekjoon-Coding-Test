/* BOJ - 16561 3의 배수 */

#include <iostream>

using namespace std;

void solve() {
	int n, answer;
	cin >> n;

	n /= 3;
	answer = (n - 1) * (n - 2) / 2;
	cout << answer << '\n';
}

int main(void) {
	solve();

	return 0;
}