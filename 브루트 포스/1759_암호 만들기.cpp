/* BOJ - 1759 암호 만들기 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(string password) {
	int vowel = 0, consonant = 0;
	for (char ch : password) {
		switch (ch) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			vowel++;
			break;
		default:
			consonant++;
			break;
		}
	}

	return vowel >= 1 && consonant >= 2;
}

void go(int l, vector<char> &alphabet, string password, int index) {
	if (password.size() == l) {
		if (check(password))
			cout << password << '\n';
		return;
	}
	if (alphabet.size() <= index) return;
	go(l, alphabet, password + alphabet[index], index + 1);
	go(l, alphabet, password, index + 1);
}

void solve() {
	int l, c;
	cin >> l >> c;

	vector<char> alphabet(c);
	for (int i = 0; i < c; i++)
		cin >> alphabet[i];
	sort(alphabet.begin(), alphabet.end());

	vector<char> password(l);
	go(l, alphabet, "", 0);
}

int main(void) {
	solve();

	return 0;
}