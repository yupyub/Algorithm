#include <cstdio>
#include <unordered_map>
using namespace std;
typedef long long ll;

int N, S;
int arr[40];
unordered_map<int, ll> cnt[2]; //그냥 map으로는 시간초과가 발생한다.

int check(int start_idx, int end_idx, int map_id){
    int len = end_idx - start_idx + 1;
    int ret = 0;
	for (ll i = 0; i<(1 << len); i++){
		int sum = 0;
		for (int j = 0; j<len; j++){
			if (i&(1 << j))
				sum += arr[start_idx+j];
		}
		cnt[map_id][sum] += 1;
	}
    return ret;
}

int main(){	
    scanf("%d %d", &N, &S);
	for (int i = 0; i<N; i++){
		scanf("%d", &arr[i]);
	}
    ll ans = 0;
    if(N < 20){
        check(0, N-1, 0);
        ans = cnt[0][S];
    }
    else{
        int n = N/2;
        check(0, n, 0);
        check(n+1, N-1, 1);
        for(auto iter = cnt[0].begin(); iter != cnt[0].end(); iter++){
            ans += (iter -> second) * cnt[1][S-(iter -> first)];
        }
    }
    if(S == 0)
        ans -= 1;
    printf("%lld\n", ans);
    return 0;
}