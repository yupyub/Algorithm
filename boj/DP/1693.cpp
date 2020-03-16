#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 987654321
const int COLOR = 15; // 정석적으로는 18
vector<int> graph[100001];
int visit[100001];
int dp[100001][COLOR];
void fill(int node){
	for(int i : graph[node]){
		if(!visit[i]){
			visit[i] = node;
			fill(i);
		}
	}
	int min1 = INF,min2 = INF,col1,col2;
	for(int i = 1;i<COLOR;i++){
		int tot_cost = i;
		for(int j : graph[node]){
			if(visit[j] != node)
				continue;
			tot_cost += dp[j][i];
		}
		if(tot_cost<min1){
			min2 = min1;
			col2 = col1;
			min1 = tot_cost;
			col1 = i;
		}
		else if(tot_cost<min2){
			min2 = tot_cost;
			col2 = i;
		}
	}
	for(int i = 1;i<COLOR;i++)
		dp[node][i] = min1;
	dp[node][col1] = min2;
}
int main(){
	int n,a,b;
	scanf("%d",&n);
	for(int i = 0;i<n-1;i++){
		scanf("%d %d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	visit[1] = 1;
	fill(1);
	int ans = 0;
	for(int i = 1;i<COLOR;i++)
		ans = dp[1][i];
	printf("%d\n",ans);
	return 0;
}