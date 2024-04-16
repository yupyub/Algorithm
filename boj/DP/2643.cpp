#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;


int main(){
    int N;
    pair<int, int> arr[100];
    int dp[101] = {0, };
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%d %d", &arr[i].first, &arr[i].second);
        if(arr[i].first > arr[i].second)
            swap(arr[i].first, arr[i].second);
    }
    sort(arr, arr+N);
    int w;
    for(int i = 0; i<N; i++){
        dp[i] = 1;
        for(int j = 0; j<i; j++){
            if(arr[j].first <= arr[i].first && arr[j].second <= arr[i].second)
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    int ans = 0;
    for(int i = 0; i<N; i++){
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}