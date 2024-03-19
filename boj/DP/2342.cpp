#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[100001];
int dp[100001][5][5];

int main(){
    int a, l = 0;
    while(1){
        scanf("%d", &a);
        if(a == 0)
            break;
        arr[++l] = a;
    }
    for(int i = 0; i<=l; i++)
        for(int j = 0; j<5; j++)
            for(int k = 0; k<5; k++)
                dp[i][j][k] = 10000000;
    dp[0][0][0] = 0;
    int cost;
    for(int i = 1; i<=l; i++){
        for(int j = 0; j<5; j++){
            for(int k = 0; k<5; k++){
                if(j == k)
                    continue;
                if(j == arr[i]){
                    for(int p = 0; p<5; p++){
                        if(p == 0)
                            cost = 2;
                        else if(j == p)
                            cost = 1;
                        else if(abs(j-p) == 2)
                            cost = 4;
                        else
                            cost = 3;
                        dp[i][j][k] = min(dp[i][j][k], dp[i-1][p][k] + cost);
                    }
                }
                if(k == arr[i]){
                    for(int p = 0; p<5; p++){
                        if(p == 0)
                            cost = 2;
                        else if(k == p)
                            cost = 1;
                        else if(abs(k-p) == 2)
                            cost = 4;
                        else
                            cost = 3;
                        dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][p] + cost);
                    }
                }
            }
        }
    }
    int ans = 10000000;
    for(int j = 0; j<5; j++){
        for(int k = 0; k<5; k++){
            ans = min(ans, dp[l][j][k]);
        }
    }
    printf("%d\n", ans);
    return 0;
}