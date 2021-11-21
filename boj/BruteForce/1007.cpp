#include <cstdio>
#include <algorithm>
#include <utility>
#include <cmath>
#define INF 987654321
using namespace std;
typedef pair<double, double> Point;
double calc(int N, Point points[], Point sum, int idx, int choosen) {
	if (choosen == (N / 2)) 
		return sqrt((sum.first) * (sum.first) + (sum.second) * (sum.second));
	if (idx >= N)
		return INF;
	double mini = INF;
	mini = min(mini, calc(N, points, sum, idx + 1, choosen));
	sum.first -= 2 * points[idx].first;
	sum.second -= 2 * points[idx].second;
	mini = min(mini, calc(N, points, sum, idx + 1, choosen + 1));
	return mini;
}
int main() {
	int T, N;
	Point points[20];
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		Point sum = make_pair(0, 0);
		for (int i = 0; i < N; i++) {
			scanf("%lf %lf", &points[i].first, &points[i].second);
			sum.first += points[i].first;
			sum.second += points[i].second;
		}
		printf("%.7lf\n", calc(N, points, sum, 0, 0));
	}
	return 0;
}