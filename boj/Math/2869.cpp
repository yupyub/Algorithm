#include<cstdio>
int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if((c-a)%(a-b) == 0) printf("%d\n",(c-a)/(a-b)+1);
	else printf("%d\n",(c-a)/(a-b)+2);
}