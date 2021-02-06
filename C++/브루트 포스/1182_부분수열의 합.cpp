/* BOJ - 1182 부분수열의 합 */

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, s;
	cin >> n >> s;

	vector<int> sequence(n);
	for (int i = 0; i < n; i++)
		cin >> sequence[i];

	int answer = 0;
	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int k = 0; k < n; k++)
			if (i & (1 << k))
				sum += sequence[k];
		
		if (sum == s)
			answer += 1;
	}

	cout << answer << '\n';
}

int main(void) {
	solve();

	return 0;
}