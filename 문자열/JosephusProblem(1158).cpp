/* 백준알고리즘 - 1158 요세푸스 문제 */

#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	int n, k;
	queue<int> queue;

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		queue.push(i);

	cout << '<';
	while (queue.size() > 1) {
		for (int j = 1; j < k; j++) {
			queue.push(queue.front());
			queue.pop();
		}
		cout << queue.front() << ", ";
		queue.pop();
	}
	cout << queue.front() << '>';
	
	return 0;
}