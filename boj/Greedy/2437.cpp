#include <cstdio>
#include <algorithm>
using namespace std;
int arr[1001];
int main(){
	int n,ans = 0,sum = 0;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
		ans += arr[i];
	}
	ans++;
	sort(arr,arr+n);
	for(int i = 0;i<n;i++){
		if(sum+1 < arr[i]){
			ans = sum+1;
			break;
		}
		sum += arr[i];
	}
	printf("%d\n",ans);
}