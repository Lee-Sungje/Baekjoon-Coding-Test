/* BOJ - 1748 수 이어 쓰기 1 */

#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int ans = 0, k = 1;
	for (int i = 1; k <= n; i++) {
		if (k * 10 <= n)
			ans += i * (k * 10 - k);
		else
			ans += i * (n - k + 1);	
		
		k *= 10;
	}
	cout << ans << '\n';

	return 0;
}