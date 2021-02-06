/* BOJ - 14226 이모티콘 */

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

constexpr int MAX_SIZE = 1001;
constexpr int OPERATION = 3;

int s;
int dist[MAX_SIZE][MAX_SIZE];

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 1, 0 });
	dist[1][0] = 0;

	while (!q.empty()) {
		int emoticon = q.front().first;
		int clipboard = q.front().second;
		q.pop();

		if (emoticon == s) {
			cout << dist[emoticon][clipboard] << '\n';
			return;
		}

		int operEmoticon[] = { emoticon, emoticon + clipboard, emoticon - 1 };
		int operClipboard[] = { emoticon, clipboard, clipboard };
		for (int op = 0; op < OPERATION; op++) {
			int e = operEmoticon[op], c = operClipboard[op];
			if (0 <= e && e < MAX_SIZE) {
				if (dist[e][c] == -1) {
					q.push({ e, c });
					dist[e][c] = dist[emoticon][clipboard] + 1;
				}
			}
		}
	}
}

void solve() {
	cin >> s;
	memset(dist, -1, sizeof(dist));
	bfs();
}

int main(void) {
	solve();

	return 0;
}