/* 백준알고리즘 - 1463 1로 만들기 */

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n;

	cin >> n;
	vector<int> memo(n +1);
	
	for (int i = 2; i <= n; i++)	{
		memo[i] = memo[i - 1] + 1;
		if (i % 2 == 0 && memo[i] > memo[i / 2] + 1)
			memo[i] = memo[i / 2] + 1;
		if (i % 3 == 0 && memo[i] > memo[i / 3] + 1)
			memo[i] = memo[i / 3] + 1;
	}
	
	cout << memo[n] << '\n';

	return 0;
}