/* BOJ - 17298 오큰수 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void) {
	int n;

	cin >> n;

	vector<int> a(n);
	vector<int> nge(n, -1);
	for (int idx = 0; idx < n; idx++)
		cin >> a[idx];

	stack<int> stack;
	for (int idx = 0; idx < n - 1; idx++) {
		while (!stack.empty()) {
			if (a[stack.top()] < a[idx + 1]) {
				nge[stack.top()] = a[idx + 1];
				stack.pop();
			} else
				break;
		}

		if (a[idx] < a[idx + 1])
			nge[idx] = a[idx + 1];
		else if (a[idx] >= a[idx + 1])
			stack.push(idx);
	}

	for_each(nge.begin(), nge.end(), [](int e) { cout << e << ' '; });

	return 0;
}