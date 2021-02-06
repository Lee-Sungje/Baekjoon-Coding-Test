/* BOJ - 12865 평범한 배낭 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Item {
	int value;
	int weight;

	Item(int _value, int _weight) : value(_value), weight(_weight) {}
};

constexpr int MAX_WEIGHT = 100'001;

int n, k;
int knapsack[MAX_WEIGHT];
vector<Item> items;

void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;
		items.push_back(Item(v, w));
	}
}

void pack() {
	for (int index = 0; index < n; index++) {
		for (int weight = k; weight > 0; weight--) {
			if (items[index].weight <= weight) {
				knapsack[weight] = max(knapsack[weight],
					knapsack[weight - items[index].weight] + items[index].value);
			}
		}
	}
}

void solve() {
	input();
	pack();

	cout << knapsack[k] << '\n';
}

int main(void) {
	solve();

	return 0;
}