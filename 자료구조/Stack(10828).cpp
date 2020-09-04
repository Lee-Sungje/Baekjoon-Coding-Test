/* 백준알고리즘 - 10828 스택 */

#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int stack[10000];
	int size = 0;
	int T;

	cin >> T;
	while (T--) {
		string command;
		cin >> command;

		if (command == "push") {
			int X;
			cin >> X;
			stack[size++] = X;
		} else if (command == "pop") {
			if (size)
				cout << stack[size-- - 1] << '\n';
			else
				cout << -1 << '\n';
		} else if (command == "size") {
			cout << size << '\n';
		} else if (command == "empty") {
			if (size)
				cout << 0 << '\n';
			else
				cout << 1 << '\n';
		} else if (command == "top") {
			if (size)
				cout << stack[size - 1] << '\n';
			else
				cout << -1 << '\n';
		}

	}

	return 0;
}