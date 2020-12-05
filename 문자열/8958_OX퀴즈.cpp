/* BOJ - 8958 OX퀴즈 */

#include <iostream>
#include <string>

using namespace std;

constexpr int MAX_SIZE = 81;

int memo[MAX_SIZE];

int grade(int cnt) {
	if (cnt == 0) return 0;

	if (memo[cnt] == 0)
		memo[cnt] = cnt + grade(cnt - 1);

	return memo[cnt];
}

void solve() {
	int testcase;
	cin >> testcase;

	while (testcase--) {
		string str;
		cin >> str;

		int score = 0, cnt = 0;
		for (char ch : str) {
			if (ch == 'O')
				cnt += 1;
			else {
				score += grade(cnt);
				cnt = 0;
			}
		}
		score += grade(cnt);

		cout << score << '\n';
	}
}

int main() {
	solve();

	return 0;
}