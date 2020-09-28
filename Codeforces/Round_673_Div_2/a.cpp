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
int arr[1000];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d %d",&n,&k);
		int mini = INF;
		int idx = 0;
		for(int i = 0;i<n;i++){
			scanf("%d",&arr[i]);
			if(mini>arr[i]){
				mini = arr[i];
				idx = i;
			}
		}
		int ans = 0;
		for(int i = 0;i<n;i++){
			if(i == idx) continue;
			ans += (k-arr[i])/mini;
		}
		printf("%d\n",ans);
	}
}