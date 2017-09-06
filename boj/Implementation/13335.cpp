#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int arr[10000];
int main() {
	int n, w, l;
	scanf("%d %d %d", &n, &w, &l);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	queue<pair<int, int> >q;
	int weight = 0, t = 0;
	for (int i = 0; i < n; i++) {
		t++;
		while (weight + arr[i]>l) {
			weight -= q.front().first;
			t = max(t, q.front().second);
			//printf("%d\n", t);
			q.pop();
		}
		weight += arr[i];
		q.push(make_pair(arr[i], t + w));
	}
	while (!q.empty()) {
		t = q.front().second;
		//printf("%d\n", t);
		q.pop();
	}
	printf("%d\n", t);
}