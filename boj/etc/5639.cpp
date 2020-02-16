#include <cstdio>
int tree[10000];
int n;
int f(int i){
	if(i == n-1) return i;
	if(tree[i]>tree[i+1]){
		int nx = f(i+1);
		printf("%d ",tree[i]);
		f(nx+1);
	}
	else if(tree[i-1]<tree[i+1]){
		printf("%d ",tree[i]);
		return i;
	}
}
int main(){
	while(scanf("%d",&tree[n++]) != EOF){
		if(tree[n-1] == -1) break;
	}
	f(0);
}