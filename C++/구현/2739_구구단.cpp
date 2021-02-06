/* BOJ - 2739 구구단 */

#include <cstdio>

using namespace std;

int main(void) {
	int dan;
	scanf("%d", &dan);

	for (int i = 1; i <= 9; i++)
		printf("%d * %d = %d\n", dan, i, dan * i);

	return 0;
}