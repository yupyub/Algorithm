#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>
#include <map>

#define FOR(i,n) for(int i=0; i<n ;i++)
using namespace std;

int a,b,c,d,e,f;

int main(){

    cin >> a >> b >> c>>d>>e >> f;
    int x, y;

    y=(c*d-f*a)/(b*d-e*a);
    if(a!=0)
        x= (c-b*y)/a;
    else {
        x = (f - e * y) / d;
    }

    cout << x << ' ' <<  y << '\n';

}