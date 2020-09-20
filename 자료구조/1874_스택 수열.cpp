/* BOJ - 1874 스택 수열 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	int n;
	int m = 0;
	string str = "";
	stack<int> stack;

	cin >> n;
	while (n--) {
		int x;
		cin >> x;

		if (m < x) {
			while (m < x) {
				stack.push(++m);
				str += "+\n";
			};
			stack.pop();
			str += "-\n";
		} else {
			if (x == stack.top()) {
				stack.pop();
				str += "-\n";
			} else {
				str = "NO";
				break;
			}
		}
	}

	cout << str;

	return 0;
}