#include <cstdio>

void p(int a,int b,int k){
	if(k == 1){
		printf("%d %d\n",a,b);
		return;
	}
	int c = 6-(a+b);
	p(a,c,k-1);
	p(a,b,1);
	p(c,b,k-1);
}
int f(int n){
	if(n == 1) return 1;
	return 2*f(n-1) + 1;
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",f(n));
	p(1,3,n);
}