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
#include <set>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = 987654321;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
vector<vector<int> > g;
int sav[100001];
int arr[100001];
int parent[100001];
int isEx[100001];
int isEnd[100001];
int Find(int x){
	if (x == parent[x])
		return x;
	else
		parent[x] = Find(parent[x]);
	return parent[x];
}
void Union(int x, int y){
	parent[Find(x)] = Find(y);
}
int main(){
	int n,m,x,a;
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	g.resize(m);
	for(int i = 0;i<m;i++){
		scanf("%d",&x);
		for(int j = 0;j<x;j++){
			scanf("%d",&a);
			g[i].push_back(a);
		}
	}
	int vic = 0;
	for(int i = 1;i<=n;i++){
		scanf("%d",&arr[i]);
		sav[i] = arr[i];
		if(arr[i] == 1){
			vic = 1;
		}
	}
	if(vic == 0){
		printf("YES\n");
		for(int i = 0;i<n;i++){
			printf("0 ");
		}
		printf("\n");
		return 0;
	}
	for(int i = m-1;i>=0;i--){
		vic = 0;
		int pr = 0;
		for(int x : g[i]){
			if(arr[x] == 0){
				vic = 1;
			}
			if(pr == 0){
				pr = x;
				continue;
			}
			if(Find(x) != Find(pr)){
				Union(x,pr);
			}
			pr = x;
		}
		if(vic)
			for(int x : g[i]){
				arr[x] = 0;
			}
	}
	int ans = 1;
	for(int i = 1;i<=n;i++){
		//printf("%d : %d %d %d\n",i,sav[i],arr[i],parent[i]);
		if(sav[i] == 1){
			isEx[Find(i)] = 1;
		}
		if(arr[i] == 1){
			isEnd[Find(i)] = 1;
		}
	}
	for(int i = 1;i<=n;i++){
		if(isEx[i] != isEnd[i])
			ans = 0;
	}
	if(ans){
		printf("YES\n");
		for(int i = 1;i<=n;i++)
			printf("%d ",arr[i]);
		printf("\n");
	}
	else
		printf("NO\n");
	
}
