#include <cstdio>
int parent[201];
int Find(int n){
	if(parent[n] == n) 
		return n;
	return parent[n] = Find(parent[n]);
}
void Union(int a,int b){
	parent[Find(a)] = Find(b);
}
int main(){
	int n,m,a,b;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n;i++)
		parent[i] = i;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			scanf("%d",&a);
			if(a == 1)
				Union(i,j);
		}
	}
	scanf("%d",&a);
	int ans = 0;
	for(int i = 1;i<m;i++){
		scanf("%d",&b);
		if(Find(a-1) != Find(b-1)){
			ans = 1;
			break;
		}
	}
	if(ans)
		printf("NO\n");
	else
		printf("YES\n");
}