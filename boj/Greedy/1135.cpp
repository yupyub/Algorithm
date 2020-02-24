#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int parent[55];
vector<int> graph[55];
int dfs(int n){
	int maxi = 0;
	vector<int> sub;
	for(int nx : graph[n])
		sub.push_back(-dfs(nx));
	sort(sub.begin(),sub.end());
	for(int i = 0;i<sub.size();i++){
		int ti = -sub[i];
		maxi = max(maxi,ti+i+1);
	}
	return maxi;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d",&parent[i]);
		graph[parent[i]].push_back(i);
	}
	printf("%d\n",dfs(0));
	return 0;	
}