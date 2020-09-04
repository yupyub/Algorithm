#define _CRT_SECURE_NO_WARNINGS
 
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <functional>
#include <queue>
#include <math.h>
#include <memory.h>
 
 
int readInt();
 
 
int N, K;
int X[3001], Y[3001];
 
void GatherInput() {
    N = readInt();
    K = readInt();
    for (int i = 1; i <= N; i++) X[i] = readInt();
    for (int i = 1; i <= N; i++) Y[i] = readInt();
}
 
// DP[i][j] = X[1..i], Y[1..j]가 남았을 때 이길 수 있는지; 1=승, 0=패
int DP[3001][3001];
 
// SummableX[i] = X[j..i] 합이 k 이하인 j값 중 가장 작은 것
int SummableX[3001], SummableY[3001];
 
// DP_PsumX[i+1][j+1] = DP[0][j] + DP[1][j] + ... + DP[i][j].
// DP_PsumY[i+1][j+1] = DP[i][0] + DP[i][1] + ... + DP[i][j].
int DP_PsumX[3002][3002], DP_PsumY[3002][3002];
 
void Solve() {
    auto compute_summables = [](int* in, int* out, int Count) {
        /* two-pointer algorithm */
        out[1] = 1;
        int sum = in[1], p = 1;
        for (int i = 2; i <= N; i++) {
            sum += in[i];
            while (sum > K) sum -= in[p++];
            out[i] = p;
        }
    };
    compute_summables(X, SummableX, N);
    compute_summables(Y, SummableY, N);
 
    /* actual DP */
    // DP[i][j] = (k-j, i-k들 중, 가능한 것이 있을 때,
    //             그 k중 이길 수 있는 방법이 하나라도 있으면 1 없으면 0)
 
    DP[0][0] = 1;
    memset(DP_PsumX, 0, sizeof(DP_PsumX));
    memset(DP_PsumY, 0, sizeof(DP_PsumY));
    DP_PsumX[1][1] = DP_PsumY[1][1] = DP[0][0];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (i == 0 && j == 0) continue;
 
            int lo;
            bool Winnable = false;
 
            /* picking from deck X */
            if (i > 0) {
                lo = SummableX[i];
                if (DP_PsumX[i][j + 1] - DP_PsumX[lo - 1][j + 1] < (i - lo + 1)) {
                    /* DP[lo - 1][j] + DP[lo][j] + ... + DP[i - 1][j] 중 0이 있음 */
                    Winnable = true;
                }
            }
 
            /* picking from deck Y */
            if (j > 0) {
                lo = SummableY[j];
                if (DP_PsumY[i + 1][j] - DP_PsumY[i + 1][lo - 1] < (j - lo + 1)) {
                    /* DP[i][lo - 1] + DP[i][lo] + ... + DP[i][j - 1] 중 0이 있음 */
                    Winnable = true;
                }
            }
 
            /* save and cleanup */
            DP[i][j] = Winnable ? 1 : 0;
            DP_PsumX[i + 1][j + 1] = DP_PsumX[i][j + 1] + DP[i][j];
            DP_PsumY[i + 1][j + 1] = DP_PsumY[i + 1][j] + DP[i][j];
        }
    }
 
    int WinnableStates = 0;
    for (int i = 0; i <= N; i++) WinnableStates += DP_PsumY[i + 1][N + 1];
    int LosingStates = (N + 1) * (N + 1) - WinnableStates;
 
    printf("%d %d\n", WinnableStates, LosingStates);
}
 
 
 
int main() {
    int T = readInt();
    setbuf(stdout, NULL);
 
    for (int test_case = 1; test_case <= T; test_case++) {
        GatherInput();
        printf("Case #%d\n", test_case);
        Solve();
    }
    return 0;
}
 
int readInt() {
    int p;
    scanf("%d", &p);
    return p;
}