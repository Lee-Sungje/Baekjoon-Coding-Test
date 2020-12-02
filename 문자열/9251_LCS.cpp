/* BOJ - 9251 LCS */

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

constexpr int MAX_LENGTH = 1'001;

int dp[MAX_LENGTH][MAX_LENGTH];

int LCS(string &str1, string &str2) {	
	int r, c;
	for (r = 1; r <= str1.size(); r++) {
		for (c = 1; c <= str2.size(); c++) {
			if (str1[r - 1] == str2[c - 1])
				dp[r][c] = dp[r - 1][c - 1] + 1;
			else
				dp[r][c] = max(dp[r][c - 1], dp[r - 1][c]);
		}
	}

	return dp[r - 1][c - 1];
}

void solve() {
	string str1, str2;
	cin >> str1;
	cin >> str2;
	
	cout << LCS(str1, str2) << '\n';
}

int main(void) {
	solve();

	return 0;
}