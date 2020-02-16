#include <cstdio>
int f(int n,int mod){
	int ret = 0;
	while(n!=0){
		ret += n%mod;
		n /= mod;
	}
	return ret;
}
int main(){
	for(int i = 1000;i<10000;i++){
		int a = f(i,10);
		int b = f(i,12);
		int c = f(i,16);
		if(a == b && b == c)
			printf("%d\n",i);
	}
	return 0;
}