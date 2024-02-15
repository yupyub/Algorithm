#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;

/*
f(n) = f(n-1) + f(n-2)
f(n-1) = f(n-2) + f(n-3)
f(n-2) = f(n-3) + f(n-4)
f(n-3) = f(n-4) + f(n-5)
f(n-4) = f(n-5) + f(n-6)

f(n) = f(2) * f(n-1) + f(1) * f(n-2)
f(n) = f(3) * f(n-2) + f(2) * f(n-3)
f(n) = f(4) * f(n-3) + f(3) * f(n-4)
f(n) = (2+1+1+1) * f(n-4) + (2+1) * f(n-5)

f(n) = f(k) * f(n-k+1) + f(k-1) * f(n-k)
n = k + m
f(k + m) = f(k) * f(m+1) + f(k-1) * f(m)
f(n + m) = f(n) * f(m+1) + f(n-1) * f(m)

N = 2n
f(N) = f(n) * f(n+1) + f(n-1) * f(n)

N = 2n + 1
f(N) = f(n) * f(n+2) + f(n-1) * f(n+1)
*/

map <ll, ll> fibo;
ll MOD = 1000000007;

ll dq(ll N){
    map <ll, ll>::iterator tmp = fibo.find(N);
    if(tmp != fibo.end())
        return tmp -> second;
    ll ret;
    if(N%2 == 0){
        // f(N) = f(n) * f(n+1) + f(n-1) * f(n)
        ll fn0 = dq(N/2);
        ll fn1 = dq(N/2+1);
        ll fn2 = dq(N/2-1);
        ret = ((fn0 * fn1)%MOD + (fn2 * fn0)%MOD) % MOD;
    }
    else{
        // f(N) = f(n) * f(n+2) + f(n-1) * f(n+1)
        ll fn0 = dq(N/2);
        ll fn1 = dq(N/2+2);
        ll fn2 = dq(N/2-1);
        ll fn3 = dq(N/2+1);
        ret = ((fn0 * fn1)%MOD + (fn2 * fn3)%MOD) % MOD;
    }
    fibo.insert(make_pair(N, ret));
    return ret;
}

int main(){
    fibo.insert(make_pair(0, 0));
    fibo.insert(make_pair(1, 1));
    fibo.insert(make_pair(2, 1));
    fibo.insert(make_pair(3, 2));
    fibo.insert(make_pair(4, 3));
    fibo.insert(make_pair(5, 5));
    ll n;
    scanf("%lld", &n);
    printf("%lld", dq(n));
    return 0;
}
