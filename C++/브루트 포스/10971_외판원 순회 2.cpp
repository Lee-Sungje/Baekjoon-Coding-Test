/* BOJ - 10971 외판원 순회 2 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int intMax = 2147483647;
int w[10][10];

int cost_calc(vector<int> &d, int length) {
	bool isGoing = true;

	int cost = 0;
	for (int i = 0; i < length - 1; i++) {
		if (w[d[i]][d[i + 1]])
			cost += w[d[i]][d[i + 1]];
		else
			isGoing = false;
	}

	if (isGoing && w[d[length - 1]][d[0]])
		return cost + w[d[length - 1]][d[0]];
	else
		return intMax;
}

int main(void) {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> w[i][j];

	vector<int> d(n);
	for (int i = 0; i < n; i++)
		d[i] = i;

	int min = intMax;
	do {
		int temp = cost_calc(d, n);
		if (temp < min)
			min = temp;
	} while (next_permutation(d.begin() + 1, d.end()));
	cout << min << '\n';

	return 0;
}