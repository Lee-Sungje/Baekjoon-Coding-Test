/* BOJ - 11721 열 개씩 끊어 출력하기 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr size_t kCuttingLength = 10;

void solve() {
	string original_word;
	cin >> original_word;

	size_t position = 0;
	vector<string> words;
	while (position + kCuttingLength < original_word.length()) {
		words.push_back(original_word.substr(position, kCuttingLength));
		position += kCuttingLength;
	}
	words.push_back(original_word.substr(position));

	for (string word : words)
		cout << word << '\n';
}

int main(void) {
	solve();

	return 0;
}