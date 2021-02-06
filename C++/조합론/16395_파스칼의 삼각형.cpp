/* BOJ - 16395 파스칼의 삼각형 */

#include <algorithm>
#include <iostream>

using namespace std;

typedef unsigned long long ULL;
constexpr int MAX_SIZE = 31;

ULL pascal[MAX_SIZE][MAX_SIZE];

ULL combination(int n, int r) {
	if (r == 0 || n == r) return pascal[r][n] = 1;

	if (pascal[r][n] == 0)
		pascal[r][n] = combination(n - 1, r) + combination(n - 1, r - 1);

	return pascal[r][n];
}

void solve() {
	int n, k;
	cin >> n >> k;
	cout << combination(n - 1, k - 1) << '\n';
}

int main(void) {
	solve();

	return 0;
}