#include <cstdio>
long long arr[30];
long long f(int n){
	long long &ret = arr[n];
	if(ret != -1) 
		return ret;
	if(n == 0)
		return ret = 0;
	if(n == 1)
		return ret = 1;
	return ret = f(n-1)+f(n-2);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<=n;i++)
		arr[i] = -1;
	printf("%lld\n",f(n));
}