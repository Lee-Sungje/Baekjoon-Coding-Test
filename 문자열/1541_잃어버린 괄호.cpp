/* BOJ - 1541 잃어버린 괄호 */

#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

vector<int> parsing(string expression, string regular) {
	vector<int> result;
	regex re(regular);
	smatch match;

	while (regex_search(expression, match, re)) {
		result.push_back(stoi(match.str()));
		expression = match.suffix();
	}

	return result;
}

void solve() {
	string expression;
	vector<int> number;

	cin >> expression;
	number = parsing(expression, "(-?[0-9]{1,5})");

	int answer = 0;
	bool isMinus = false;
	for (int num : number) {
		if (num < 0) isMinus = true;

		if (isMinus)
			answer -= abs(num);
		else
			answer += num;
	}
	cout << answer << '\n';
}

int main(void) {
	solve();

	return 0;
}