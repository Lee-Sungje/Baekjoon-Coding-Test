/* 백준알고리즘 - 9093 단어 뒤집기 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main (void) {
	int T;

	cin >> T;
	cin.ignore();
	while (T--) {
		string sentence;
		getline(cin, sentence);
		sentence += '\n';
		
		stack<char> word;
		for (char ch : sentence) {
			if (ch == ' ' || ch == '\n') {
				while (!word.empty()) {
					cout << word.top();
					word.pop();
				}
				cout << ch;
			} else {
				word.push(ch);
			}
		}
	}

	return 0;
}