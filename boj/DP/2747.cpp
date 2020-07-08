#include <cstdio>
long long arr[50];
int main(){
	int n;
	scanf("%d",&n);
	arr[0] = 0;
	arr[1] = 1;
	for(int i = 2;i<=n;i++)
		arr[i] = arr[i-1] + arr[i-2];
	printf("%lld\n",arr[n]);
}