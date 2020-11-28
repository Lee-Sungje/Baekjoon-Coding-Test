/* BOJ - 2941 크로아티아 알파벳 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> croatiaAlphabet = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
string replaceString = "*";

void solve() {
	string str;
	cin >> str;

	for (string alphabet : croatiaAlphabet) {
		int pos = str.find(alphabet);
		while (pos != string::npos) {
			str.replace(pos, alphabet.size(), replaceString);
			pos = str.find(alphabet);
		}
	}
	cout << str.size() << '\n';
}

int main(void) {
	solve();

	return 0;
}