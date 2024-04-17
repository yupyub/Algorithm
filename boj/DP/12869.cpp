#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    int dp[61][61][61];
    int attack[6][3] = {
        {9, 3, 1},
        {9, 1, 3},
        {1, 3, 9},
        {1, 9, 3},
        {3, 9, 1},
        {3, 1, 9}
    };
    int arr[3] = {0, };
    for(int i = 0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+3);
    for(int i = 0; i<=60; i++){
        for(int j = 0; j<=60; j++){
            for(int k = 0; k<=60; k++){
                dp[i][j][k] = 100;
            }
        }
    }
    dp[arr[0]][arr[1]][arr[2]] = 0;
    int ni, nj, nk;
    int ans = 0;
    for(int t = 1; t<=14; t++){
        for(int i = 0; i<=60; i++){
            for(int j = 0; j<=60; j++){
                for(int k = 0; k<=60; k++){
                    for(int a = 0; a<6; a++){
                        ni = max(0, i-attack[a][0]);
                        nj = max(0, j-attack[a][1]);
                        nk = max(0, k-attack[a][2]);
                        dp[ni][nj][nk] = min(dp[ni][nj][nk], dp[i][j][k] + 1);
                    }
                }
            }
        }
        if(dp[0][0][0] != 100)
            break;
    }
    printf("%d\n", dp[0][0][0]);
    return 0;
}