#include <cstdio>
typedef long long ll;

/*
0 ~ N 까지 숫자들의 1의 합
101101

100000 : 00000 ~ 11111 : 1의 개수 = 2^5 - 1
001000 : 000 ~ 111 : 1의 개수 = 2^3 - 1
000100 : 00 ~ 11 : 1의 개수 = 2^2 - 1
000001 : 0
2^10 = 10^3
10 ^ 16

000  0
001  1
010  1
011  2 : 2^2
100  1
101  2
110  2
111  3 : 2^2 + 2^2
= 3 * 2^2

000  0
001  1
010  1
011  2 : 2^2
100  1
101  2
110  2
111  3 : 2^2 + 2^2
= 3 * 2^2

2 * 2^2 + 3 * 2^2

00000 ~ 11111 1의 개수

p = 5
A[p]
0xxxx : A[p-1]
1xxxx : 2^(p-1) + A[p-1]

*/
// 10 ^ 16 <= 2 ^ 54
ll two_pow(ll p){
    ll ret = 1;
    for(int i = 0; i<p; i++){
        ret *= 2;
    }
    return ret;
}

int main(){
    ll A, B;
    scanf("%lld %lld", &A, &B);
    ll pp[55] = {0, };
    pp[0] = 0;
    for(int i = 1; i<55; i++){
        pp[i] = 2 * pp[i-1] + two_pow(i-1);
    }
    ll totA = 0;
    ll totB = 0;
    for(int i = 54; i>=0; i--){
        if(((ll)1<<i) & B){
            B = B & ~((ll)1<<i);
            totB += pp[i] + B + 1;
        }
    }
    A--;
    for(int i = 54; i>=0; i--){
        if(((ll)1<<i) & A){
            A = A & ~((ll)1<<i);
            totA += pp[i] + A + 1;
        }
    }
    printf("%lld\n", totB - totA);

    return 0;
}