/* BOJ - 14002 가장 긴 증가하는 부분 수열 4 */

#include <iostream>

using namespace std;

int a[1000];
int d[1000];
int v[1000];

void chase(int p) {
	if (p == -1)
		return;
	chase(v[p]);
	cout << a[p] << ' ';
}

int main(void) {
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++) {
		d[i] = 1;
		v[i] = -1;
		for (int j =0; j < i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
				v[i] = j;
			}
		}
	}

	int ans = d[0];
	int p = 0;
	for (int i = 0; i < n; i++) {
		if (ans < d[i]) {
			ans = d[i];
			p = i;
		}
	}

	cout << ans << '\n';
	chase(p);
	cout << '\n';

	return 0;
}