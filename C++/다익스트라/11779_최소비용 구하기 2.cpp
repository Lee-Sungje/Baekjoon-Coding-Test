/* BOJ - 11779 최소비용 구하기 2 */

#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

typedef pair<int, int> P;
constexpr int MAX_CITY = 1'001;
constexpr int INF = 100'000'000;

int city, bus, start, goal;
int trace[MAX_CITY];
vector<P> adj[MAX_CITY];

void input() {
	cin >> city;
	cin >> bus;

	int from, to, cost;
	for (int i = 0; i < bus; i++) {
		cin >> from >> to >> cost;
		adj[from].push_back({ cost, to });
	}
	cin >> start >> goal;
}

int dijkstra() {
	vector<int> cost(city + 1, INF);
	priority_queue<P> pq;

	cost[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int current = pq.top().second;
		int currentCost = -pq.top().first;
		pq.pop();

		if (cost[current] < currentCost) continue;

		for (int i = 0; i < adj[current].size(); i++) {
			int next = adj[current][i].second;
			int nextCost = adj[current][i].first + currentCost;

			if (nextCost < cost[next]) {
				cost[next] = nextCost;
				pq.push({ -nextCost, next });
				trace[next] = current;
			}
		}
	}

	return cost[goal];
}

void tracing() {
	stack<int> s;
	s.push(goal);
	while (s.top() != start)
		s.push(trace[s.top()]);

	cout << s.size() << '\n';
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
}

void solve() {
	input();
	cout << dijkstra() << '\n';
	tracing();
}

int main(void) {
	solve();

	return 0;
}