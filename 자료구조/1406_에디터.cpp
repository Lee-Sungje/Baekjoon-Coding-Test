/* BOJ - 1406 에디터 */

#include <iostream>
#include <string>
#include <stack>

const char cursor_left_move = 'L';
const char cursor_right_move = 'D';
const char character_delete = 'B';
const char character_insert = 'P';

using namespace std;

int main(void) {
	stack<char> left, right;
	string init_string;

	cin >> init_string;
	for (char ch : init_string)
		left.push(ch);

	int T;

	cin >> T;
	while (T--) {
		char command;
		
		cin >> command;
		switch (command) {
		case cursor_left_move:
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
			break;
		case cursor_right_move:
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
			break;
		case character_delete:
			if (!left.empty())
				left.pop();
			break;
		case character_insert:
			char ch;
			
			cin >> ch;
			left.push(ch);
			break;
		}
	}

	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}

	string result = "";
	while (!right.empty()) {
		result += right.top();
		right.pop();
	}
	cout << result << '\n';

	return 0;
}