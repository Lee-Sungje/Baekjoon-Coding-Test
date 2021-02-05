/* BOJ - 10869 사칙연산 */

#include <cstdio>

using namespace std;

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n%d\n%d\n%d\n%d\n", a + b, a - b, a*b, a / b, a%b);

	return 0;
}