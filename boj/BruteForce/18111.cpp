#include <cstdio>
#include <algorithm>
using namespace std;
int map[500][500];
int main(){
	int n,m,d;
	int mini = -1,maxi = 260,tot = 0;
	scanf("%d %d %d",&n,&m,&d);
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			scanf("%d",&map[i][j]);
			mini = min(mini,map[i][j]);
			maxi = max(maxi,map[i][j]);
			tot += map[i][j];
		}
	}
	int ans_t = 987654321,ans;
	for(int h = mini;h<=maxi;h++){
		if(tot+d<h*n*m) break;
		int ti = 0;
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				if(map[i][j] < h)
					ti += h - map[i][j];
				else
					ti += 2*(map[i][j] - h);
			}
		}
		if(ans_t>=ti){
			ans_t = ti;
			ans = h;
		}
	}
	printf("%d %d\n",ans_t,ans);
}