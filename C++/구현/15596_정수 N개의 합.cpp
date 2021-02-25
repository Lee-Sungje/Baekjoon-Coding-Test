/* BOJ - 15596 정수 N개의 합 */

#include <algorithm>
#include <vector>

long long sum(std::vector<int> &a) {
	long long ans = 0;
	for_each(a.begin(), a.end(), [&](int number) { ans += number; });

	return ans;
}