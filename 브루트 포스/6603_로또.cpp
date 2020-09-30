/* BOJ - 6603 로또 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<int> &s, int k) {
	vector<int> d;
	for (int i = 0; i < 6; i++)		d.push_back(1);
	for (int i = 0; i < k - 6; i++)	d.push_back(0);

	vector<vector<int>> answer;
	do {
		vector<int> current;
		for (int i = 0; i < k; i++) {
			if (d[i] == 1)
				current.push_back(s[i]);
		}
		answer.push_back(current);
	} while (prev_permutation(d.begin(), d.end()));

	for (auto &element : answer) {
		for (int i = 0; i < 6; i++)
			cout << element[i] << ' ';
		cout << '\n';
	}

}

int main(void) {
	int k;
	
	do {
		cin >> k;

		if (k != 0) {
			vector<int> s(k);
			for (int i = 0; i < k; i++)
				cin >> s[i];
			solve(s, k);
			cout << '\n';
		}
	} while (k != 0);

	return 0;
}