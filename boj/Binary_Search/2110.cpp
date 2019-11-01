#include <cstdio>
#include <algorithm>
using namespace std;
long long arr[200000];
int main()
{
	int n,c;
	scanf("%d %d",&n,&c);
	for(int i = 0;i<n;++i)
		scanf("%lld",&arr[i]);
	sort(arr,arr+n);
	long long start = 0,end = 1000000000,mid,ans = 0,sum;
	int count;
	while(start <=end)
	{
		mid = (start+end)/2;
		count = 1;
		sum = 0;
		for(int i = 1;i<n;i++){
			sum += arr[i] - arr[i-1];
			if(sum>=mid){
				count++;
				sum = 0;
			}
		}
		if(count<c)
			end = mid-1;
		else{
			if(ans<mid)
				ans = mid;
			start = mid+1;
		}
	}
	printf("%lld\n",ans);
}