#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <tuple>
#include <functional>
using namespace std;
int arr[301][301];
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i = 0;i<n;i++)
			for(int j = 0;j<m;j++)
				scanf("%d",&arr[i][j]);
		int ans = 0;
		if(arr[0][0] >2)
			ans = 1;
		if(arr[n-1][0]>2)
			ans = 1;
		if(arr[0][m-1]>2)
			ans = 1;
		if(arr[n-1][m-1]>2)
			ans = 1;
		for(int i = 1;i<n-1;i++){
			if(arr[i][0]>3) {
				ans = 1;
				break;
			}
			if(arr[i][m-1]>3){
				ans = 1;
				break;
			}
		}
		for(int i = 1;i<m-1;i++){
			if(arr[0][i]>3) {
				ans = 1;
				break;
			}
			if(arr[n-1][i]>3){
				ans = 1;
				break;
			}
		}
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				if(arr[i][j] > 4){
					ans = 1;
					break;
				}
			}
			if(ans)
				break;
		}
		if(ans)
			printf("NO\n");
		else{
			printf("YES\n");
			printf("2 ");
			for(int i = 1;i<m-1;i++)
				printf("3 ");
			printf("2\n");
			for(int i = 1;i<n-1;i++){
				printf("3 ");
				for(int j = 1;j<m-1;j++){
					printf("4 ");
				}
				printf("3\n");
			}
			printf("2 ");
			for(int i = 1;i<m-1;i++)
				printf("3 ");
			printf("2\n");
		}
		
	}
}