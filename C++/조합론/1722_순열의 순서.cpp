/* BOJ - 1722 순열의 순서 */

#include <iostream>

using namespace std;

typedef unsigned long long ULL;
constexpr int N_RANGE = 21;

int n, option;
ULL answer;
ULL factoral[N_RANGE];
bool isCheck[N_RANGE];

ULL calcFactoral(int n) {
	if (n == 0)
		return factoral[n] = 1;
	else
		return factoral[n] = n * calcFactoral(n - 1);
}

void solve() {
	cin >> n;
	cin >> option;

	calcFactoral(n);
	if (option == 1) {
		cin >> answer;
		answer -= 1;
		for (int i = n; i > 0; i--) {
			int num = answer / factoral[i - 1] + 1;
			answer %= factoral[i - 1];

			for (int j = 1; j <= num; j++)
				if (isCheck[j])
					num += 1;
			isCheck[num] = true;
			
			cout << num << ' ';
		}
	} else if (option == 2) {
		answer = 1;

		for (int i = n; i > 0; i--) {
			int num;
			cin >> num;

			for (int j = 1; j < num; j++)
				if (!isCheck[j])
					answer += factoral[i - 1];
			isCheck[num] = true;
		}
		cout << answer;
	}
}

int main(void) {
	solve();

	return 0;
}