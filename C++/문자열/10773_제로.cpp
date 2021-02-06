/* BOJ - 10773 제로 */

#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

void input() {
	int k, num;

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> num;
		if (!s.empty() && num == 0)
			s.pop();
		else
			s.push(num);
	}
}

void solve() {
	int answer = 0;

	input();
	while (!s.empty()) {
		answer += s.top();
		s.pop();
	}
	cout << answer << '\n';
}

int main(void) {
	solve();

	return 0;
}