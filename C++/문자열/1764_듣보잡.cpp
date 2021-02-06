/* BOJ - 1764 듣보잡 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> noHear, noSee;

void input() {
	int n, m;
	cin >> n >> m;

	string name;
	for (int i = 0; i < m; i++) {
		cin >> name;
		noHear.push_back(name);
	}

	for (int i = 0; i < n; i++) {
		cin >> name;
		noSee.push_back(name);
	}
}

void output(vector<string> &answer) {
	cout << answer.size() << '\n';

	for (string name : answer)
		cout << name << '\n';
}

void solve() {
	input();

	sort(noHear.begin(), noHear.end());
	sort(noSee.begin(), noSee.end());

	vector<string> answer;
	for (string name : noSee) {
		if (binary_search(noHear.begin(), noHear.end(), name))
			answer.push_back(name);
	}
	
	output(answer);
}

int main(void) {
	solve();

	return 0;
}