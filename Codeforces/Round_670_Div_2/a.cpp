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
typedef long long ll;
typedef pair<int,int> ii;
const int INF = 987654321;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int arr[100];
int num[110];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i = 0;i<=100;i++)
			num[i] = 0;
		for(int i = 0;i<n;i++){
			scanf("%d",&arr[i]);
			num[arr[i]]++;
		}
		int ans = 0;
		for(int i = 0;i<102;i++){
			for(int j = i;j<102;j++){
				// i <= j
				int fl = 0;
				for(int k = 0;k<j;k++){
					if(num[k] == 0){
						fl = 1;
						break;
					}
				}
				for(int k = 0;k<i;k++){
					if(num[k] <= 1){
						fl = 1;
						break;
					}
				}
				if(fl) continue;
				if(i == j && num[i] == 0){
					ans = max(ans,i+i);
				}
				else if(i != j){
					if(num[i] < 2 && num[j]<2)
						ans = max(ans,i+j);
				}
			}
		}
		printf("%d\n",ans);
	}
}