/* BOJ - 1152 단어의 개수 */

#include <iostream>
#include <string>

using namespace std;

constexpr int SPACE = 0x20;

int wordCount(string& str) {
	int cnt = 1;

	for (char ch : str) {
		if (ch == SPACE)
			cnt += 1;
	}
	
	if (str.front() == SPACE) cnt -= 1;
	if (str.back() == SPACE) cnt -= 1;

	return cnt;
}

void solve() {
	string str;
	getline(cin, str);
	cout << wordCount(str) << '\n';
}

int main() {
	solve();

	return 0;
}