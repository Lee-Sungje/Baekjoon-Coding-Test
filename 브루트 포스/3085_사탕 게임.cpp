/* BOJ - 3085 사탕 게임 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int check(vector<string> &a) {
	int ans = 0;

	int n = a.size();
	for (int i = 0; i < n; i++) {
		int count = 1;
		for (int j = 1; j < n; j++) {
			if (a[i][j] == a[i][j - 1])
				count++;
			else
				count = 1;

			if (ans < count) ans = count;
		}

		count = 1;
		for (int j = 1; j < n; j++) {
			if (a[j][i] == a[j - 1][i])
				count++;
			else
				count = 1;

			if (ans < count) ans = count;
		}
	}

	return ans;
}

int main(void) {
	int n;
	cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			if (j + 1 < n) {
				swap(a[i][j], a[i][j + 1]);
				temp = check(a);
				ans = ans < temp ? temp : ans;
				swap(a[i][j], a[i][j + 1]);
			}

			if (i + 1 < n) {
				swap(a[i][j], a[i + 1][j]);
				temp = check(a);
				ans = ans < temp ? temp : ans;
				swap(a[i][j], a[i + 1][j]);
			}
		}
	}
	cout << ans << '\n';

	return 0;
}