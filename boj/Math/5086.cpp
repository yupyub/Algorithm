#include <cstdio>
int main(){
	int a,b;
	while(1){
		scanf("%d %d",&a,&b);
		if(a == 0) break;
		if(b%a == 0){
			printf("factor\n");
			continue;
		}
		else if(a%b == 0){
			printf("multiple\n");
			continue;
		}
		else
			printf("neither\n");
	}
}