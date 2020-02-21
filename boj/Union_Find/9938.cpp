#include <cstdio>
int visit[300001];
int parent[300001];
int Find(int a){
	if(parent[a] == a)
		return a;
	return parent[a] = Find(parent[a]);
}
void Union(int a,int b){
	parent[Find(a)] = Find(b);
}
int main(){
	int n,l,a,b;
	scanf("%d %d",&n,&l);
	for(int i = 1;i<=l;i++)
		parent[i] = i;
	for(int i = 0;i<n;i++){
		scanf("%d %d",&a,&b);
		if(visit[a] == 0 || visit[Find(a)] == 0){
			visit[Find(a)] = 1;
			Union(a,b);
			printf("LADICA\n");
		}
		else if(visit[b] == 0 || visit[Find(b)] == 0){
			visit[Find(b)] = 1;
			Union(b,a);
			printf("LADICA\n");
		}
		else{
			printf("SMECE\n");
		}
	}
}