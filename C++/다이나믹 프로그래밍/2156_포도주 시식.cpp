/* BOJ - 2156 포도주 시식 */

#include <iostream>
#include <algorithm>

using namespace std;

int w[10'001];
int d[10'001];

int dp(int n) {
	if (n >= 3)
		if (!d[n])
			d[n] = max({ dp(n - 1), dp(n - 2) + w[n], dp(n - 3) + w[n] + w[n - 1] });

	return d[n];
}

int main(void) {
	int n;

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> w[i];

	d[1] = w[1];
	d[2] = w[2] + w[1];
	cout << dp(n) << '\n';

	return 0;
}