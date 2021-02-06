/* BOJ - 1316 그룹 단어 체커 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int ALPHABET = 26;

bool checker(string &str) {
	vector<bool> check(ALPHABET, false);
	char previous;

	for (char c : str) {
		if (!check[c - 'a'] || c == previous) {
			check[c - 'a'] = true;
			previous = c;
		} else {
			return false;
		}
	}

	return true;
}

void solve() {
	int testcase;
	cin >> testcase;

	int answer = 0;
	while (testcase--) {
		string str;
		cin >> str;

		if (checker(str))
			answer += 1;
	}
	cout << answer << '\n';
}

int main(void) {
	solve();

	return 0;
}