/* BOJ - 11726 2xn 타일링 */

#include <iostream>

using namespace std;

const int modulo_number = 10007;
const int memory_size = 1001;

int memory[memory_size] = { 0, };

int tiling(int n) {
	if (n <= 2) {
		return n;
	} else {
		if (!memory[n])
			memory[n] = tiling(n - 1) + tiling(n - 2);

		return memory[n] % modulo_number;
	}
}

int main(void) {
	int n;

	cin >> n;
	cout << tiling(n) << '\n';

	return 0;
}