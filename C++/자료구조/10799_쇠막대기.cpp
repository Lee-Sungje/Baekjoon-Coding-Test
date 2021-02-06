/* BOJ - 10799 쇠막대기 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
	int count = 0;
	bool isLaser = false;
	string str;
	stack<char> stack;

	getline(cin, str);
	for (char ch : str) {
		if (ch == '(') {
			stack.push(ch);
			isLaser = true;
		} else if (ch == ')') {
			stack.pop();
			if (isLaser) {
				count += stack.size();
				isLaser = false;
			} else {
				count++;
			}
		}
	}
	cout << count;

	return 0;
}