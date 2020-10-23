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
pair<int,int> arr[100000];
int ans[100000];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		int div = -1;
		if(m%2 == 0){
			div = m/2;
		}
		int a;
		int cnt = 0;
		for(int i = 0;i<n;i++){
			scanf("%d",&arr[i].first);
			arr[i].second = i;
			if(arr[i].first == div){
				cnt++;
			}
			ans[i] = 0;
		}
		cnt/=2;
		for(int i = 0;i<n;i++){
			if(arr[i].first == div){
				if(cnt){
					cnt--;
					ans[arr[i].second] = 1;
				}
			}
			else if(arr[i].first>m/2){
				ans[arr[i].second] = 1;
			}
		}
		for(int i = 0;i<n;i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
}