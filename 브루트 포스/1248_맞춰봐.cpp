/* BOJ - 1248 맞춰봐 */

#include <iostream>

using namespace std;

int n;
char s[10][10];
int answer[10];

bool check(int index) {
	int sum = 0;
	for (int i = index; i >= 0; i--) {
		sum += answer[i];
		if (s[i][index] == '0') {
			if (sum != 0)	return false;
		} else if (s[i][index] == '-') {
			if (sum >= 0)	return false;
		} else if (s[i][index] == '+') {
			if (sum <= 0)	return false;
		}
	}
	return true;
}

bool go(int index = 0) {
	if (index == n) return true;
	if (s[index][index] == '0') {
		answer[index] = 0;
		return check(index) && go(index + 1);
	}

	for (int i = 1; i <= 10; i++) {
		if (s[index][index] == '-')
			answer[index] = i * (-1);
		else if (s[index][index] == '+')
			answer[index] = i;

		if (check(index) && go(index + 1)) return true;
	}
	return false;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			cin >> s[i][j];

	go();

	for (int i = 0; i < n; i++)
		cout << answer[i] << ' ';
	cout << '\n';
}

int main(void) {
	solve();

	return 0;
}