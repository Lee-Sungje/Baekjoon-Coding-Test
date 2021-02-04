/* BOJ - 11719 그대로 출력하기 2 */

#include <iostream>
#include <string>

using namespace std;

void solve() {
	string line;

	do {
		getline(cin, line);
		cout << line << '\n';
	} while (!cin.eof());
}

int main(void) {
	solve();

	return 0;
}