/* BOJ - 2529 부등호 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
char a[10];
bool check[10];
vector<string> answer;

bool valid_check(string number) {
	for (int i = 0; i < n; i++) {
		if (a[i] == '>' && number[i] < number[i + 1])
			return false;
		if (a[i] == '<' && number[i] > number[i + 1])
			return false;
	}

	return true;
}

void go(int index = 0, string number = "") {
	if (index == n + 1) {
		if (valid_check(number))
			answer.push_back(number);
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (check[i])	continue;
		check[i] = true;
		go(index + 1, number + to_string(i));
		check[i] = false;
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