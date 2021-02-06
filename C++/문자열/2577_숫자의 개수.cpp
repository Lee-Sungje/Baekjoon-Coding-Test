/* BOJ - 2577 숫자의 개수 */

#include <iostream>
#include <string>

using namespace std;
constexpr int DECIMAL = 10;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	
	int cnt[DECIMAL] = { 0 };
	string result = to_string(a * b * c);
	
	for (char number : result)
		cnt[number - '0'] += 1;

	for (int i = 0; i < DECIMAL; i++)
		cout << cnt[i] << '\n';
}

int main() {
	solve();

	return 0;
}