#include <cstdio>
#include <queue>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;

int main(){
    ll s, e;
    scanf("%lld %lld", &s, &e);
    queue<pair<ll, int> > q;
    set<ll> visit;
    q.push(make_pair(s, 1));
    visit.insert(s);
    ll n, nx;
    int d, ans = -1;
    while(!q.empty()){
        n = q.front().first;
        d = q.front().second;
        q.pop();
        if(n == e){
            ans = d;
            break;
        }
        nx = n * 10 + 1;
        if(nx <= e && visit.find(nx) == visit.end()){
            visit.insert(nx);
            q.push(make_pair(nx, d+1));
        }
        nx = n * 2;
        if(nx <= e && visit.find(nx) == visit.end()){
            visit.insert(nx);
            q.push(make_pair(nx, d+1));
        }
    }
    printf("%d\n", ans);
    return 0;
}