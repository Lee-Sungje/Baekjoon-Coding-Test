/* BOJ - 2775 부녀회장이 될테야 */

#include <iostream>

using namespace std;

constexpr int MAX_SIZE = 15;

int apartment[MAX_SIZE][MAX_SIZE];

void census() {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			if (i == 0)
				apartment[i][j] = j;
			else if (j < 2)
				apartment[i][j] = j;
			else
				apartment[i][j] = apartment[i - 1][j] + apartment[i][j - 1];
		}
	}
}

void solve() {
	census();

	int testcase;
	cin >> testcase;
	while (testcase--) {
		int n, k;
		cin >> n;
		cin >> k;
		cout << apartment[n][k] << '\n';
	}
}

int main(void) {
	solve();

	return 0;
}