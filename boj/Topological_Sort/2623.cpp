#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
vector<int> graph[1001];
int visit[1001];
int finish[1001];
stack<int> s;
int dfs(int n){
	if(finish[n]) return 1;
	if(visit[n]) return 0;
	visit[n] = finish[n] = 1;
	for(int i : graph[n]){
		if(dfs(i))
			return 1;
	}
	finish[n] = 0;
	s.push(n);
	return 0;
}
int main(){
	int n,m,m_num,a,b;
	scanf("%d %d",&n,&m);
	while(m--){
		scanf("%d",&m_num);
		scanf("%d",&a);
		m_num--;
		while(m_num--){
			scanf("%d",&b);
			graph[a].push_back(b);
			a = b;
		}
	}
	int cant = 0;
	for(int i = 1;i<=n;i++){
		if(visit[i] == 0){
			if(dfs(i)){
				cant = 1;
				break;
			}
		}
	}
	if(cant)
		printf("0\n");
	else{
		while(!s.empty()){
			printf("%d\n",s.top());
			s.pop();
		}
	}
}