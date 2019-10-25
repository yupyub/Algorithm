#include <cstdio>
int arr[1000001];
int f(int n){
	int sum = 0;
	while(n!=0){
		sum += n%10;
		n /= 10;
	}
	return sum;
}
int main(){
	int n,tmp;
	scanf("%d",&n);
	for(int i = 1;i<1000001;i++){
		tmp = i + f(i);
		if(arr[tmp] == 0) arr[tmp] = i;
		else if(arr[tmp]>i) arr[tmp] = i;
	}
	printf("%d",arr[n]);
}
