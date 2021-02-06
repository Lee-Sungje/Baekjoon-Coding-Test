/* BOJ - 1916 최소비용 구하기 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr int MAX_CITY = 1'001;
constexpr int INF = 100'000'000;

int city, bus, departurue, arrival;
vector<pair<int, int>> adj[MAX_CITY];

void input() {
	cin >> city;
	cin >> bus;
	
	int from, to, cost;
	for (int i = 0; i < bus; i++) {
		cin >> from >> to >> cost;
		adj[from].push_back({ to, cost });
	}
	cin >> departurue >> arrival;
}

int dijkstra() {
	vector<int> answer(city + 1, INF);
	priority_queue<pair<int, int>> pq;

	pq.push({ 0, departurue });
	answer[departurue] = 0;

	while (!pq.empty()) {
		int current = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (answer[current] < cost) continue;

		for (size_t i = 0; i < adj[current].size(); i++) {
			int next = adj[current][i].first;
			int nextCost = adj[current][i].second + cost;

			if (nextCost < answer[next]) {
				answer[next] = nextCost;
				pq.push({ -nextCost, next });
			}
		}
	}
	return answer[arrival];
}

void solve() {
	input();
	cout << dijkstra() << '\n';
}

int main(void) {
	solve();
	
	return 0;
}