#include <cstdio>
int main(){
	int n;
	scanf("%d",&n);
	printf("%d",(n*(n+1)*(2*n+1)/2 + 3*n*(n+1)/2)/2);
}