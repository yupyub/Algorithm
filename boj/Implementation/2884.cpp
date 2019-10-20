#include <cstdio>

int main(){
    int h,m;
	scanf("%d %d",&h,&m);
	int a = (h*60 + m - 45);
	if(a<0) a += 24*60;
	printf("%d %d\n",a/60,a%60);
}