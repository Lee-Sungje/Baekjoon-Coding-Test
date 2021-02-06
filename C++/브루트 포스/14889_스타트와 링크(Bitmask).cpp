/* BOJ - 14889 스타트와 링크(Bitmask) */

#include <iostream>
#include <vector>

using namespace std;

int s[20][20];

void solve() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> s[i][j];

	int answer = -1;
	for (int i = 0; i < (1 << n); i++) {
		// 팀 나누기
		vector<int> first, second;
		for (int j = 0; j < n; j++) {
			if (i &  (1 << j))
				first.push_back(j);
			else
				second.push_back(j);
		}
		if (first.size() != n / 2)	continue;
		
		// 팀 능력치 계산
		int t1 = 0, t2 = 0;
		for (int l1 = 0; l1 < n / 2; l1++) {
			for (int l2 = 0; l2 < n / 2; l2++) {
				if (l1 == l2)	continue;
				t1 += s[first[l1]][first[l2]];
				t2 += s[second[l1]][second[l2]];
			}
		}
		int difference = abs(t1 - t2);
		if (answer == -1 || answer > difference)
			answer = difference;
	}
	cout << answer << '\n';
}

int main(void) {
	solve();

	return 0;
}