#include <cstdio>
typedef long long ll;
ll arr[100000];
int main()
{
	int n;
	ll m;
	scanf("%d %lld",&n,&m);
	for(int i = 0;i<n;i++)
		scanf("%lld",&arr[i]);
	ll s = 1, e = 1000000000000000001;
	ll mid;
    ll ans = e;
	while(s<=e){
		mid = (s+e)/2;
		ll sum = 0;
		for(int i = 0;i<n;i++){
			sum += mid/arr[i];
			if(sum >= m)
				break;
		}
		if(sum<m)
			s = mid+1;
		else{
            ans = mid;
			e = mid-1;
        }
	}
	printf("%lld\n",ans);
}