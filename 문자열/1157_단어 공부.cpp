/* BOJ - 1157 단어 공부 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int ALPHABET = 26;
constexpr int ZERO = 0;

vector<int> wordCount(string& word) {
	vector<int> count(ALPHABET, ZERO);
	for (char ch : word) {
		if ('a' <= ch)
			count[ch - 'a'] += 1;
		else
			count[ch - 'A'] += 1;
	}
	return count;
}

char mostUsedAlphabet(vector<int>& count) {
	bool isMany = false;
	int index = ZERO, max = ZERO;
	for (int i = ZERO; i < ALPHABET; i++) {
		if (max == count[i]) {
			isMany = true;
		}
		else if (max < count[i]) {
			max = count[i];
			index = i;
			isMany = false;
		}
	}

	return isMany ? '?' : 'A' + index;
}

void solve() {
	string word;
	cin >> word;

	vector<int> count = wordCount(word);
	cout << mostUsedAlphabet(count) << '\n';
}

int main() {
	solve();

	return 0;
}