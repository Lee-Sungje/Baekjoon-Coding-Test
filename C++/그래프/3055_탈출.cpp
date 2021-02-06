/* BOJ - 3055 탈출 */

#include <iostream>
#include <deque>

using namespace std;

constexpr int MAP_SIZE = 51;
constexpr int DIRECTION = 4;
constexpr int DIRECTION_X[] = { 0, 1, 0, -1 };
constexpr int DIRECTION_Y[] = { -1, 0, 1, 0 };

enum Area {
	START = 0,
	NORMAL = -1,
	WATER = -2,
	ROCK = -3,
	DEN = -4
};

struct Position {
	int row;
	int column;

	Position() {}
	Position(int _row, int _column) : row(_row), column(_column) {}
};

int r, c;
char map[MAP_SIZE][MAP_SIZE];
int dist[MAP_SIZE][MAP_SIZE];
deque<Position> deq;
Position answer;

void input() {
	cin >> r >> c;
	for (int row = 0; row < r; row++)
		cin >> map[row];
}

void mapScan() {
	for (int row = 0; row < r; row++) {
		for (int column = 0; column < c; column++) {
			if (map[row][column] == 'S') {
				deq.push_front(Position(row, column));
				dist[row][column] = START;
			} else if (map[row][column] == '.') {
				dist[row][column] = NORMAL;
			} else if (map[row][column] == '*') {
				deq.push_back(Position(row, column));
				dist[row][column] = WATER;
			} else if (map[row][column] == 'X') {
				dist[row][column] = ROCK;
			} else if (map[row][column] == 'D') {
				answer = Position(row, column);
				dist[row][column] = DEN;
			}
		}
	}
}

bool isRange(int row, int column) {
	return 0 <= row && row < r && 0 <= column && column < c ? true : false;
}

bool isArrival(int row, int column) {
	return DEN != dist[row][column] ? true : false;
}

bool isMove(int row, int column) {
	return NORMAL == dist[row][column] || DEN == dist[row][column] ? true : false;
}

bool isFlow(int row, int column) {
	return WATER < dist[row][column] ? true : false;
}

bool bfs() {
	while (!deq.empty()) {
		Position current = deq.front();
		deq.pop_front();

		for (int d = 0; d < DIRECTION; d++) {
			Position next = Position(current.row + DIRECTION_Y[d], current.column + DIRECTION_X[d]);

			if (START <= dist[current.row][current.column]) {
				if (isRange(next.row, next.column) && isMove(next.row, next.column)) {
					dist[next.row][next.column] = dist[current.row][current.column] + 1;
					deq.push_back(next);

					if (isArrival(answer.row, answer.column))
						return true;
				}
			} else if (WATER == dist[current.row][current.column]) {
				if (isRange(next.row, next.column) && isFlow(next.row, next.column)) {
					dist[next.row][next.column] = WATER;
					deq.push_back(next);
				}
			}
		}
	}
	return false;
}

void solve() {
	input();
	mapScan();

	if (bfs())
		cout << dist[answer.row][answer.column] << '\n';
	else
		cout << "KAKTUS" << '\n';
}

int main(void) {
	solve();

	return 0;
}