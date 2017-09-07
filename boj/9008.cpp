#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<pair<int, int>, int> >vx;
vector<pair<pair<int, int>, int> >vy;
vector<pair<pair<int, int>, pair<int, int> > >vl;
int cnt[10000];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		vx.clear();
		vy.clear();
		vl.clear();
		int n, a, b, ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			cnt[i] = 0;
			scanf("%d %d", &a, &b);
			vx.push_back(make_pair(make_pair(a, b), i));
			vy.push_back(make_pair(make_pair(b, a), i));
		}
		sort(vx.begin(), vx.end());
		sort(vy.begin(), vy.end());
		int x = -1000001;
		int y = -1000001;
		int z = 0;
		int bfo = 0;
		int count = 0;
		/*
		printf("====================\n");
		for (int i = 0; i < n; i++) {
			printf("%d %d\n", vx[i].first.first, vx[i].first.second);
		}
		printf("====================\n");
		*/
		for (int i = 0; i < n; i++) {
			if (vx[i].first.first != x) {
				if (count % 2) {
					printf("1 NO\n");
					ans = 1;
					break;
				}
				x = vx[i].first.first;
				y = vx[i].first.second;
				z = vx[i].second;
				bfo = 0;
				count = 1;
			}
			else if (bfo == 0) {
				vl.push_back(make_pair(make_pair(x, y), make_pair(vx[i].first.first, vx[i].first.second)));
				cnt[vx[i].second]++;
				cnt[z]++;
				x = vx[i].first.first;
				y = vx[i].first.second;
				z = vx[i].second;
				bfo = 1;
				count++;
			}
			else {
				x = vx[i].first.first;
				y = vx[i].first.second;
				z = vx[i].second;
				bfo = 0;
				count++;
			}
		}
		if (ans)
			continue;
		if (count % 2) {
			printf("2 NO\n");
			ans = 1;
			break;
		}
		if (ans)
			continue;
		//printf(">>>>>>>> 1 YES\n");
		x = -1000001;
		y = -1000001;
		z = 0;
		bfo = 0;
		count = 0;
		for (int i = 0; i < n; i++) {
			if (vy[i].first.first != y) {
				if (count % 2) {
					printf("3 NO\n");
					ans = 1;
					break;
				}
				x = vy[i].first.second;
				y = vy[i].first.first;
				z = vy[i].second;
				bfo = 0;
				count = 1;
			}
			else if (bfo == 0) {
				vl.push_back(make_pair(make_pair(x, y), make_pair(vy[i].first.second, vy[i].first.first)));
				cnt[vy[i].second]++;
				cnt[z]++;
				x = vy[i].first.second;
				y = vy[i].first.first;
				z = vy[i].second;
				bfo = 1;
				count++;
			}
			else {
				x = vy[i].first.second;
				y = vy[i].first.first;
				z = vy[i].second;
				bfo = 0;
				count++;
			}
		}
		if (ans)
			continue;
		if (count % 2) {
			printf("4 NO\n");
			ans = 1;
			break;
		}
		if (ans)
			continue;
		for (int i = 0; i < n; i++) {
			if (cnt[i] != 2) {
				printf("5 NO\n");
				ans = 1;
				break;
			}
		}
		if (ans)
			continue;
		printf(">>>>>>>> 2 YES\n");
		pair<int, int> p1, p2, p3, p4;
		for (int i = 0; i < vl.size(); i++) {
			p1 = vl[i].first;
			p2 = vl[i].second;
			for (int j = i + 1; j < vl.size(); j++) {
				p3 = vl[j].first;
				p4 = vl[j].second;
				if (p1.second == p2.second && p3.first == p4.first) {
					//printf("(%d %d) (%d %d) (%d %d) (%d %d)\n", p1.first, p1.second, p2.first, p2.second, p3.first, p3.second, p4.first, p4.second);
					if (p1.first<p4.first && p2.first > p4.first) {
						if (p1.second > p3.second && p1.second < p4.second) {
							printf("(%d %d) (%d %d) (%d %d) (%d %d)\n", p1.first, p1.second, p2.first, p2.second, p3.first, p3.second, p4.first, p4.second);
							printf("6 NO\n");
							ans = 1;
							break;
						}
					}
				}
				else if(p1.first == p2.first && p3.second == p4.second){
					//printf("(%d %d) (%d %d) (%d %d) (%d %d)\n", p1.first, p1.second, p2.first, p2.second, p3.first, p3.second, p4.first, p4.second);
					if (p1.first>p3.first && p1.first<p4.first) {
						if (p3.second > p1.second && p3.second < p2.second) {
							printf("(%d %d) (%d %d) (%d %d) (%d %d)\n", p1.first, p1.second, p2.first, p2.second, p3.first, p3.second, p4.first, p4.second);
							printf("7 NO\n");
							ans = 1;
							break;
						}
					}
				}
			}
			if (ans)
				break;
		}
		if (!ans)
			printf(">>>>>>>> 3 YES\n");
	}

}