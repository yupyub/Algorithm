#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <tuple>
#include <climits>
#include <cmath>
#include <map>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = 987654321;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
vector<vector<int> > g;
int arr[100001];
int ansArr[100001];
int prevArr[100001];
int main(){
	int n,m,x,a;
	scanf("%d %d",&n,&m);
	g.resize(m);
	for(int i = 0;i<m;i++){
		scanf("%d",&x);
		for(int j = 0;j<x;j++){
			scanf("%d",&a);
			g[i].push_back(a);
		}
	}
	for(int i = 1;i<=n;i++){
		scanf("%d",&arr[i]);
		prevArr[i] = arr[i];
	}
	int vic;
	for(int i = m-1;i>=0;i--){
		vic = 0;
		for(int x : g[i]){
			if(arr[x] == 0){
				vic = 1;
				break;
			}
		}
		if(vic)
			for(int x : g[i]){
				arr[x] = 0;
			}
	}
	for(int i = 1;i<=n;i++)
		ansArr[i] = arr[i];
	for(int i = 0;i<m;i++){
		vic = 0;
		for(int x : g[i]){
			if(arr[x] == 1){
				vic = 1;
				break;
			}
		}
		if(vic)
			for(int x : g[i]){
				arr[x] = 1;
			}
	}
	int ans = 1;
	for(int i = 1;i<=n;i++){
		if(prevArr[i] != arr[i]){
			ans = 0;
			break;
		}
	}
	if(ans){
		printf("YES\n");
		for(int i = 1;i<=n;i++)
			printf("%d ",ansArr[i]);
		printf("\n");
	}
	else
		printf("NO\n");
	
}
