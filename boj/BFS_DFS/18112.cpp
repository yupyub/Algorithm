#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int main() {
	char str1[11];
	char str2[11];
	scanf("%s", str1);
	scanf("%s", str2);
	int num1 = 0;
	int num2 = 0;
	for (int i = 0; i < strlen(str1); i++) {
		num1 *= 2;
		if (str1[i] == '1')
			num1 += 1;
	}
	for (int i = 0; i < strlen(str2); i++) {
		num2 *= 2;
		if (str2[i] == '1')
			num2 += 1;
	}
	int visit[(1 << 12)] = { 0, };
	queue<pair<long long, int> >q;
	q.push(make_pair(num1, 0));
	while (!q.empty()) {
		int num = q.front().first;
		int count = q.front().second;
		q.pop();
		if (num == num2) {
			printf("%d", count);
			break;
		}
		if (!visit[num + 1]) {
			visit[num + 1] = 1;
			q.push(make_pair(num + 1, count + 1));
		}
		if (num != 0 && !visit[num - 1]) {
			visit[num - 1] = 1;
			q.push(make_pair(num - 1, count + 1));
		}
		for (int i = 0; i < 12; i++) {
			if ((1 << (i + 1)) > num)
				break;
			if (!visit[num ^ (1 << i)]) {
				visit[num ^ (1 << i)] = 1;
				q.push(make_pair(num ^ (1 << i), count + 1));
			}
		}
	}
	return 0;
}