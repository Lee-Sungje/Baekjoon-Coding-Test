/* BOJ - 9012 괄호 */

#include <iostream>
#include <string>

using namespace std;

string ParenthesisChecking(string s) {
	int cnt = 0;

	for (char ch : s) {
		if (ch == '(')
			cnt++;
		else if (ch == ')')
			if (cnt)
				cnt--;
			else
				return "NO";
	}

	if (cnt)
		return "NO";
	else
		return "YES"; 
}

int main(void) {
	int T;
	cin >> T;
	cin.ignore();

	while (T--) {
		string str;
		getline(cin, str);

		cout << ParenthesisChecking(str) << '\n';
	}

	return 0;
}