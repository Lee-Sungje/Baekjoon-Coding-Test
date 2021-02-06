/* BOJ - 알파벳 찾기 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int ALPHABET = 26;

void solve() {
	string word;
	cin >> word;

	vector<int> answer(ALPHABET, -1);
	for (int index = 0; index < word.length(); index++) {
		char ch = word[index];

		if (answer[ch - 'a'] == -1)
			answer[ch - 'a'] = index;
	}

	for (int n : answer)
		cout << n << ' ';
}

int main() {
	solve();

	return 0;
}