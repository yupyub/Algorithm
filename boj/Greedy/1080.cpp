#include <cstdio>
int A[50][50];
int B[50][50];
int compare(int n,int m){
	for(int i = 0;i<n;i++)
		for(int j = 0;j<m;j++)
			if(A[i][j] != B[i][j]) return 0;
	return 1;
}
void rev(int x,int y){
	for(int i = x;i<x+3;i++)
		for(int j = y;j<y+3;j++)
			A[i][j] = (A[i][j] +1)%2;
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n;i++)
		for(int j = 0;j<m;j++)
			scanf("%1d",&A[i][j]);
	for(int i = 0;i<n;i++)
		for(int j = 0;j<m;j++)
			scanf("%1d",&B[i][j]);
	int ans = 0;
	for(int i = 0;i<n-2;i++){
		for(int j = 0;j<m-2;j++){
			if(A[i][j] != B[i][j]) {
				rev(i,j);
				ans++;
			}
		}
	}
	if(compare(n,m)) printf("%d\n",ans);
	else printf("-1\n");
}
			