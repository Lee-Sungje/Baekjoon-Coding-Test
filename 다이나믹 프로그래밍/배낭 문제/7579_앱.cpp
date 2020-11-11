/* BOJ - 7579 앱 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

struct App {
	int memory;
	int cost;

	App(int _memory) : memory(_memory) {}
};

int n, m;
vector<App> app;
int answers[101][10001];

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int memory;
		cin >> memory;
		app.push_back(App(memory));
	}
	for (int i = 0; i < n; i++)
		cin >> app[i].cost;
}

int dp(int index, int cost) {
	if (index == n) return 0;

	int &ret = answers[index][cost];
	if (ret != -1) return ret;

	ret = dp(index + 1, cost);

	if (cost >= app[index].cost)
		ret = max(ret, app[index].memory + dp(index + 1, cost - app[index].cost));

	return ret;
}

void solve() {
	input();
	memset(answers, -1, sizeof(answers));
	
	for (int answer = 0; ; answer++) {
		if (dp(0, answer) >= m) {
			cout << answer << '\n';
			break;
		}
	}
}

int main(void) {
	solve();

	return 0;
}