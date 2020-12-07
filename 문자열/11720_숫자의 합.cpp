/* BOJ - 11720 숫자의 합 */

#include <iostream>
#include <string>

using namespace std;

void solve() {
	int n;
	string str;

	cin >> n;
	cin >> str;

	int sum = 0;
	for (char number : str)
		sum += number - '0';

	cout << sum << '\n';
}

int main() {
	solve();

	return 0;
}