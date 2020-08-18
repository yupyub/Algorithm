#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll arr[100000];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n;i++)
		scanf("%lld",&arr[i]);
    sort(arr,arr+n);
	ll s = 1,e = m*arr[n-1];
	ll mid;
    ll ans = m*arr[n-1];
	while(s<=e)
	{
		mid = (s+e)/2;
		ll sum = 0;
		for(int i = 0;i<n;i++)
			sum += mid/arr[i];
		if(sum<(ll)m)
			s = mid+1;
		else{
            ans = min(ans,mid);
			e = mid-1;
        }
	}
	printf("%lld\n",ans);
}