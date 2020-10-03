/* BOJ - 14501 퇴사 */

#include <iostream>

using namespace std;

int t[16];
int p[16];
int n;
int answer = 0;

void go(int day = 1, int sum = 0) {
	if (day == n + 1) {
		if (answer < sum) answer = sum;
		return;
	}
	if (day > n + 1) {
		return;
	}
	go(day + 1, sum);
	go(day + t[day], sum + p[day]);
}

void solve() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> t[i] >> p[i];
	
	go();
	cout << answer << '\n';
}

int main(void) {
	solve();

	return 0;
}