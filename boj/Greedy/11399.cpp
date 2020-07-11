#include <cstdio>
#include <algorithm>
using namespace std;
int arr[1000];
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+n);
	int ans = 0;
	int tmp = 0;
	for(int i = 0;i<n;i++){
		ans += tmp+arr[i];
		tmp += arr[i];
	}
	printf("%d\n",ans);
}