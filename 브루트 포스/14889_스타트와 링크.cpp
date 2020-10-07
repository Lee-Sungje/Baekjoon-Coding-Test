/* BOJ - 14889 스타트와 링크 */

#include <iostream>
#include <vector>

using namespace std;

int n;
int s[20][20];

int go(int index, vector<int> &first, vector<int> &second) {
	if (index == n) {
		if (n / 2 < first.size())	return -1;
		if (n / 2 < second.size())	return -1;

		int t1 = 0, t2 = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				if (i == j)		continue;
				t1 += s[first[i]][first[j]];
				t2 += s[second[i]][second[j]];
			}
		}
		return abs(t1 - t2);
	}
	
	int answer = -1;
	first.push_back(index);
	int t1 = go(index + 1, first, second);
	if (answer == -1 || (t1 != -1 && answer > t1))
		answer = t1;
	first.pop_back();

	second.push_back(index);
	int t2 = go(index + 1, first, second);
	if (answer == -1 || (t2 != -1 && answer > t2))
		answer = t2;
	second.pop_back();

	return answer;
}

void solve() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> s[i][j];

	vector<int> first, second;
	cout << go(0, first, second) << '\n';	
}

int main(void) {
	solve();

	return 0;
}