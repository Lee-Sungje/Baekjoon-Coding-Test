/* BOJ - 11053 가장 긴 증가하는 부분 수열 */

#include <iostream>
#include <algorithm>

using namespace std;

const int arr_size = 1001;

int main(void) {
	int n, ans = 0;
	int a[arr_size] = { 0, };
	int d[arr_size] = { 0, };

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i] = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (a[i] > a[j])
				d[i] = max(d[i], d[j] + 1);
		}
		ans = ans < d[i] ? d[i] : ans;
	}
	cout << ans << '\n';

	return 0;
}