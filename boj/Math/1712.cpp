#include <cstdio>
int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(c<=b) printf("-1\n");
	else printf("%d\n",a/(c-b)+1);
}