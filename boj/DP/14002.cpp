#include <cstdio>
#include <stack>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    int arr[1001] = {0, };
    for(int i = 1; i<=N; i++){
        scanf("%d", &arr[i]);
    }
    int dp[1001] = {0, };
    int prev[1001] = {0, };
    for(int i = 1; i<=N; i++){
        for(int j = 0; j<i; j++){
            if(arr[i] > arr[j]){
                if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
    }
    int ans = 0;
    int idx = 0;
    for(int i = 1; i<=N; i++){
        if(dp[i] > ans){
            ans = dp[i];
            idx = i;
        }
    }
    stack<int> st;
    while(idx != 0){
        st.push(arr[idx]);
        idx = prev[idx];
    }
    printf("%d\n", ans);
    while(!st.empty()){
        printf("%d ", st.top());
        st.pop();
    }
    return 0;
}