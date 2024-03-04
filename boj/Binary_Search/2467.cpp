#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

// ~_bound(first,last,val) : An iterator to the ~_bound of val in the range [first,last)
// upper_bound(arr,arr+n,k) : k 초과인 수가 처음으로 등장하는 위치 (iterator)
// upper_bound(~) - arr : index
// lower_bound(vector.begin(),vector.end(),k) : k 이상인 수가 처음으로 등장하는 위치 (iterator)
// lower_bound(~) - vector.begin() : index
// 두 함수 모두 탐색을 성공하지 못한 경우, last 를 return 한다

int main(){
    int N;
    int liq[100000];
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%d", &liq[i]);
    }
    int mini = 2000000001;
    int ans_x, ans_y, val, base_idx;
    for(int i = 0; i<N-1; i++){
        base_idx = lower_bound(liq+i+1, liq+N, -liq[i]) - liq;
        for(int idx = base_idx - 1; idx <= base_idx + 1; idx++){
            if(idx == i)
                continue;
            if(idx < 0 || idx >= N)
                continue;
            if(abs(liq[i] + liq[idx]) < mini){
                mini = abs(liq[i] + liq[idx]);
                ans_x = i;
                ans_y = idx;
            }
        }
    }
    printf("%d %d\n", liq[ans_x], liq[ans_y]);
    return 0;
}