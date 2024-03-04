#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

// ~_bound(first,last,val) : An iterator to the ~_bound of val in the range [first,last)
// upper_bound(arr,arr+n,k) : k 초과인 수가 처음으로 등장하는 위치 (iterator)
// upper_bound(~) - arr : index
// lower_bound(vector.begin(),vector.end(),k) : k 이상인 수가 처음으로 등장하는 위치 (iterator)
// lower_bound(~) - vector.begin() : index
// 두 함수 모두 탐색을 성공하지 못한 경우, last 를 return 한다

int main(){
    int N;
    int liq[5000];
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%d", &liq[i]);
    }
    sort(liq, liq + N);
    ll mini = 3000000001;
    int ans[3];
    for(int i = 0; i<N-2; i++){
        for(int j = i+1; j<N-1; j++){
            int val = liq[i] + liq[j];
            int base_idx = lower_bound(liq+j+1, liq+N, -val) - liq;
            for(int idx = base_idx - 1; idx <= base_idx + 1; idx++){
                if(idx == i || idx == j)
                    continue;
                if(idx < 0 || idx >= N)
                    continue;
                if(abs((ll)val + (ll)liq[idx]) < mini){
                    mini = abs((ll)val + (ll)liq[idx]);
                    ans[0] = liq[i];
                    ans[1] = liq[j];
                    ans[2] = liq[idx];
                }
            }
        }
    }
    sort(ans, ans+3);
    printf("%d %d %d\n", ans[0], ans[1], ans[2]);
    return 0;
}