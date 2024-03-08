#include <cstdio>
#include <utility>
#define pii pair<int, int>
using namespace std;
typedef long long ll;


int ccw(pii a, pii b, pii c){
    ll s = (ll)a.first * b.second;
    s += (ll)b.first * c.second;
    s += (ll)c.first * a.second;
    s -= (ll)a.second * b.first;
    s -= (ll)b.second * c.first;
    s -= (ll)c.second * a.first;
    if(s > 0)
        return 1;
    else if(s < 0)
        return -1;
    return 0;
}

int main(){
    pii line1[2];
    pii line2[2];
    scanf("%d %d %d %d", &line1[0].first, &line1[0].second, &line1[1].first, &line1[1].second);
    scanf("%d %d %d %d", &line2[0].first, &line2[0].second, &line2[1].first, &line2[1].second);
    int a = ccw(line1[0], line1[1], line2[0]);
    int b = ccw(line1[0], line1[1], line2[1]);
    int c = ccw(line2[0], line2[1], line1[0]);
    int d = ccw(line2[0], line2[1], line1[1]);
    if(a * b < 0 && c * d < 0)
        printf("1\n");
    else
        printf("0\n");
    return 0;
}