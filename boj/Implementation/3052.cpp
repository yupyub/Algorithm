#include <cstdio>
int arr[42];
int main(){
	int a;
	for(int i = 0;i<10;i++){
		scanf("%d",&a);
		arr[a%42]++;
	}
	int ans = 0;
	for(int i = 0;i<42;i++){
		if(arr[i]) ans++;
	}
	printf("%d",ans);
}