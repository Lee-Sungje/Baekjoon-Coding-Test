/* BOJ - 2529 부등호(Refactoring) */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
char a[10];
bool check[10];
vector<string> answer;

bool valid_check(char x, char y, char op) {
	if (op == '>') {
		if (x < y)	return false;
	} else if (op == '<') {
		if (x > y)	return false;
	}

	return true;
}

void go(int index = 0, string number = "") {
	if (index == n + 1) {
		answer.push_back(number);
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (check[i])	continue;
		if (index == 0 || valid_check(number[index - 1], i + '0', a[index - 1])) {
			check[i] = true;
			go(index + 1, number + to_string(i));
			check[i] = false;
		}
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	go();

	auto minmax = minmax_element(answer.begin(), answer.end());
	cout << *minmax.second << '\n';
	cout << *minmax.first << '\n';
}

int main(void) {
	solve();

	return 0;
}