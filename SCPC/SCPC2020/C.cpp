#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
const int INF = 987654321;
int Answer;		
int N,K,M;
int arr[1501];
int dp[1501][1501];
vector<pair<int,int> > g;
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		int u,v;
		scanf("%d %d %d",&N,&K,&M);
		g.clear();
		for(int i = 1;i<=N;i++)
			arr[i] = i;
		for(int i = 0;i<K;i++){
			scanf("%d %d",&u,&v);
			swap(arr[u],arr[v]);
			g.push_back(make_pair(u,v));
		}
		for(int i = 1;i<=N;i++)
			for(int j = 1;j<=N;j++)
				dp[i][j] = INF;
		for(int i = 1;i<=N;i++)
			dp[arr[i]][i] = 0;
		// for(int i = g.size()-1;i>=0;i--){
		for(int i = 0;i<g.size();i++){
			u = g[i].first;
			v = g[i].second;
			for(int j = 1;j<=N;j++){
				dp[j][u] = min(dp[j][u],dp[j][v]+1);
				dp[j][v] = min(dp[j][v],dp[j][u]+1);
			}
		}
		for(int i = 0;i<M;i++){
			scanf("%d %d",&u,&v);
			printf(">> %d %d : %d \n",u,v,dp[u][v]);
			Answer += dp[u][v] == INF ? -1 : dp[u][v];
		}
		
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}