/* BOJ - 14500 테트로미노 */

#include <iostream>

using namespace std;

const int block[19][4][2] = {
	{{0, 0}, {0, 1}, {1, 0}, {1, 1}}, // O
	{{0, 0}, {0, 1}, {0, 2}, {0, 3}}, // I
	{{0, 0}, {1, 0}, {2, 0}, {3, 0}},
	{{0, 0}, {0, 1}, {0, 2}, {1, 1}}, // T
	{{0, 1}, {1, 0}, {1, 1}, {1, 2}},
	{{0, 0}, {1, 0}, {1, 1}, {2, 0}},
	{{0, 1}, {1, 0}, {1, 1}, {2, 1}},
	{{0, 0}, {1, 0}, {1, 1}, {2, 1}}, // Z
	{{0, 1}, {1, 0}, {1, 1}, {2, 0}}, 
	{{0, 1}, {0, 2}, {1, 0}, {1, 1}}, 
	{{0, 0}, {0, 1}, {1, 1}, {1, 2}}, 
	{{0, 0}, {1, 0}, {2, 0}, {2, 1}}, // L
	{{0, 1}, {1, 1}, {2, 0}, {2, 1}},
	{{0, 0}, {0, 1}, {0, 2}, {1, 0}},
	{{0, 0}, {0, 1}, {0, 2}, {1, 2}},
	{{0, 0}, {0, 1}, {1, 1}, {2, 1}},
	{{0, 0}, {0, 1}, {1, 0}, {2, 0}},
	{{0, 0}, {1, 0}, {1, 1}, {1, 2}},
	{{0, 2}, {1, 0}, {1, 1}, {1, 2}}
};

int a[500][500];
int n, m;

int tetromino(int x, int y) {
	int ans = 0;

	for (int i = 0; i < 19; i++) {
		int weight = 0;
		for (int j = 0; j < 4; j++) {
			int current_x = x + block[i][j][0];
			int current_y = y + block[i][j][1];

			if (current_x < n && current_y < m)
				weight += a[current_x][current_y];
			else
				break;
		}
		if (ans < weight)
			ans = weight;
	}

	return ans;
}

int main(void) {	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf_s("%d", &a[i][j]);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		for (int j = 0; j < m; j++) {
			temp = tetromino(i, j);
			if (ans < temp)
				ans = temp;
		}
	}
	cout << ans << '\n';

	return 0;
}