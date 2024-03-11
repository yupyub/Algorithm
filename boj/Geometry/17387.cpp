#include <cstdio>
#include <utility>
#include <cmath>
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

bool is_big(pii a, pii b){
    if(a.first < b.first)
        return true;
    else if(a.first == b.first)
        return a.second <= b.second;
    return false;
}

bool compare(pii a, pii b, pii c){
    if(!is_big(a, b)){
        pii temp = b;
        b = a;
        a = temp;
    }
    if(is_big(a, c) && is_big(c, b))
        return true;
    return false;
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
    else if (a == 0 && compare(line1[0], line1[1], line2[0]))
        printf("1\n");
    else if (b == 0 && compare(line1[0], line1[1], line2[1]))
        printf("1\n");
    else if (c == 0 && compare(line2[0], line2[1], line1[0]))
        printf("1\n");
    else if (d == 0 && compare(line2[0], line2[1], line1[1]))
        printf("1\n");
    else
        printf("0\n");
    return 0;
}