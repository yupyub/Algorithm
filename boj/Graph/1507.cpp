#include <cstdio>
#include <algorithm>
using namespace std;
int arr[21][21];
int dist[21][21];
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			scanf("%d",&arr[i][j]);
			dist[i][j] = arr[i][j];
		}
	}
	for(int k = 0;k<n;k++){
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
			}
		}
	}
	int ans = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(arr[i][j] != dist[i][j]){ ans = -1; break;}
		}
		if(ans == -1) break;
	}
	if(ans == -1){ printf("-1\n"); return 0;} 
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			int ch = 0;
			for(int k = 0;k<n;k++){
				if(k == i || k == j) continue;
				if(arr[i][j] == arr[i][k] + arr[k][j]){ ch = 1; break;}
			}
			if(ch == 0) ans+= arr[i][j];
		}
	}
	printf("%d\n",ans);
}