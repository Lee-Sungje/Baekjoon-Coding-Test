/* BOJ - 10819 차이를 최대로 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int difference(vector<int> &a, int length) {
	int answer = 0;
	for (int i = 1; i < length; i++)
		answer += abs(a[i - 1] - a[i]);
	
	return answer;
}

int main(void) {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	sort(a.begin(), a.end());
	int max = 0;
	do {
		int temp = difference(a, n);
		if (max < temp)
			max = temp;
	} while (next_permutation(a.begin(), a.end()));
	cout << max << '\n';

	return 0;
}