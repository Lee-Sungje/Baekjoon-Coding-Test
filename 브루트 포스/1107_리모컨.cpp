/* BOJ - 1107 리모컨 */

#include <iostream>

using namespace std;

bool broken[10];

int possible(int c) {
	int count = 0;

	if (c == 0) {
		if (!broken[c])
			return 1;
		else
			return -1;
	} else if (c == 100) {
		return 0;
	} else {
		while (c) {
			if (!broken[c % 10])
				count++;
			else
				return -1;
			c /= 10;
		}
		return count;
	}
}

int main(void) {
	int n, m;

	cin >> n;
	cin >> m;	
	while (m--) {
		int i;
		cin >> i;
		broken[i] = true;
	}

	int ans = 500'000;
	for (int i = 0; i < 1'000'000; i++) {
		int c = i;
		int temp = possible(c);

		if (temp != -1)
			temp += abs(c - n);
		else 
			continue;
		
		if (ans > temp)
			ans = temp;
	}
	cout << ans << '\n';

	return 0;
}