#include <cstdio>
int check(int n){
	int ch = 0;
	while(n!=0){
		if(n%10 == 6)
			ch++;
		else ch = 0;
		if(ch == 3) break;
		n /= 10;
	}
	if(ch == 3) return 1;
	else return 0;
}
int main(){
	int n,cnt = 0;
	scanf("%d",&n);
	for(int i = 666;i<66666666;i++){
		if(check(i))cnt++;
		if(cnt == n){
			printf("%d",i);
			break;
		}
	}	
}