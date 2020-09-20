/* BOJ - 17413 단어 뒤집기 2 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string GetStack(stack<char> &stack) {
	string result = "";
	while (!stack.empty()) {
		result += stack.top();
		stack.pop();
	}

	return result;
}

int main(void) {
	bool isTag = false;
	string s, result = "";
	stack<char> stack;
	
	getline(cin, s);
	for (char ch : s) {
		if (ch == '<') {
			isTag = true;
			result += GetStack(stack) + ch;
		} else if (ch == '>') {
			isTag = false;
			result += ch;
		} else if (isTag) {
			result += ch;
		} else {
			if (ch == ' ')
				result += GetStack(stack) + ch;
			else
				stack.push(ch);
		}
	}
	cout << result + GetStack(stack);

	return 0;
}