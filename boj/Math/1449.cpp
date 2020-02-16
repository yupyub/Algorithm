#include <cstdio>
#include <algorithm>
int arr[1000];
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i = 0;i<n;i++)
		scanf("%d",&arr[i]);
    std::sort(arr,arr+n);
	int ans = 0,prev=-10000;
	for(int i = 0;i<n;i++){
		if(prev<arr[i]){
			prev = arr[i]+k-1;
			ans++;
		}
	}
	/*
	for(int i = 0;i<n;){
		int j = i;
		while(j<n-1&&arr[j+1] - arr[i]<k) j++;
		i = j+1;
		ans++;
	}
	*/
	printf("%d\n",ans);
	return 0;
}