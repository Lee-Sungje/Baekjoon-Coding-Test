/* BOJ - 1476 날짜 계산 */

#include <iostream>

using namespace std;

int main(void) {
	int e, s, m;	
	cin >> e >> s >> m;

	int year = 1;
	bool isBreak = false;
	for (int i = 1, j = 1, k = 1; !isBreak; i++, j++, k++) {
		if (i > 15) i = 1;
		if (j > 28) j = 1;
		if (k > 19) k = 1;

		if (i == e && j == s && k == m)
			isBreak = true;
		else
			year++;
	}
	cout << year << '\n';

	return 0;
}