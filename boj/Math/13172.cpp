#include <cstdio>
typedef long long ll;
#define MOD 1000000007

/*
X 는 소수
b^{-1} x b ≡ 1 (mod X)
b^{X-1} ≡ 1 (mod X)
b^{X-2} ≡ b^{-1} (mod X)

Q = 7/3, X = 11
3^{-1} ≡ 3^{11-2} (mod 11) ≡ 4 (mod 11)
Q = 7 * 4 (mod 11) = 6 (mod 11)
*/

ll pow(ll num, ll p){
    if(p == 0)
        return 1;
    else if(p == 1)
        return num;
    if(p % 2 == 0){
        ll n = pow(num, p/2);
        return (n * n) % MOD;
    }
    else{
        ll n = pow(num, (p-1)/2);
        return (((n * n) % MOD) * num) % MOD;
    }
}

int main(){
    int M;
    scanf("%d", &M);
    ll ans = 0;
    while(M--){
        ll n, s;
        scanf("%lld %lld", &n, &s);
        ans = (ans + ((s * pow(n, MOD-2)) % MOD)) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}