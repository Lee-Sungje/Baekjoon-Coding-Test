/* BOJ - 9095 1, 2, 3 더하기(Recursive) */

#include <iostream>

using namespace std;

int go(int sum, int goal) {
	if (sum > goal)	return 0;
	if (sum == goal) return 1;
	int now = 0;
	for (int i = 1; i <= 3; i++)
		now += go(sum + i, goal);

	return now;
}

void solve() {
	int n;
	cin >> n;

	cout << go(0, n) << '\n';
}

int main(void) {
	int t;
	cin >> t;

	while (t--)
		solve();

	return 0;
}