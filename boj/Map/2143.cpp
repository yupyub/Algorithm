#include <cstdio>
#include <map>
using namespace std;

int main(){
    int T, N, M;
    int A[1001] = {0, };
    int B[1001] = {0, };
    scanf("%d", &T);
    scanf("%d", &N);
    for(int i = 1; i<=N; i++){
        scanf("%d", &A[i]);
        A[i] += A[i-1];
    }
    scanf("%d", &M);
    for(int i = 1; i<=M; i++){
        scanf("%d", &B[i]);
        B[i] += B[i-1];
    }
    map<int, int> A_count;
    map<int, int> B_count;
    for(int i = 1; i<=N; i++){
        for(int j = i; j<=N; j++){
            A_count[A[j] - A[i-1]] += 1;
        }
    }
    for(int i = 1; i<=M; i++){
        for(int j = i; j<=M; j++){
            B_count[B[j] - B[i-1]] += 1;
        }
    }
    long long ans = 0;
    for(auto a : A_count){
        ans += (long long)B_count[T-a.first] * (long long)a.second;
    }
    printf("%lld\n", ans);
    return 0;
}