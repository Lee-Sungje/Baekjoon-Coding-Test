/* BOJ - 2309 일곱 난쟁이 */

#include <iostream>
#include <algorithm>

using namespace std;

const int n = 9;
int a[n];

int main(void) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (sum - (a[i] + a[j]) == 100) {
				for (int k = 0; k < n; k++) {
					if (k == i || k == j)	continue;
					cout << a[k] << '\n';
				}
				return 0;
			}
		}
	}
}