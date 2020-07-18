#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <tuple>
#include <climits>
#include <cmath>
#include <map>
#include <functional>
using namespace std;
typedef long long ll;
const int INF = 987654321;
vector<vector<int> > v;
vector<tuple<int,int,int,int> > tri;
int n;
int initMax(){
    int maxi = -INF;
    int cnt = 1;
    for(int i = 1;i<=n;i++,cnt+=2){
        for(int j = n-i+1;j<n-i+1+cnt;j++){
            maxi = max(maxi,v[i][j]-v[i][j-1]);
            if((j+i)%2 != n%2)
                tri.push_back(make_tuple(i,j,0,v[i][j]-v[i][j-1]));
            else
                tri.push_back(make_tuple(i,j,1,v[i][j]-v[i][j-1]));
        }
    }
    return maxi;
}
int retMax(int siz){
    if(siz == 1)
        return initMax();
    int maxi = -INF;
    for(int i = 0;i< tri.size();i++){
        int x = get<0>(tri[i]);
        int y = get<1>(tri[i]);
        int dir = get<2>(tri[i]);
        int tot = get<3>(tri[i]);
        int nx;
        //printf("(%d %d %d %d %d)\n",x,y,dir,tot);
        if(dir == 0)
            nx = x+siz-1;
        else
            nx = x-siz+1;
        if(nx>n || nx<1)
            continue;
        int L = n-nx+1;
        int R = L+2*nx-1;
        int l = y-siz;
        int r = y+siz;
        if(l<L-1 || r>R)
            continue;
        tot += v[nx][r-1] - v[nx][l];
        tri[i] = make_tuple(x,y,dir,tot);
        maxi = max(maxi,tot);
        //printf(">> %d %d %d %d %d\n",x,y,dir,tot,siz);
    }
    return maxi;
}
int main(){
    int tc = 1;
    while(1){
        scanf("%d",&n);
        if(n == 0)
            break;
        v.clear();
        v.resize(n+1);
        int a;
        int cnt = 1;
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<=n-i;j++)
                v[i].push_back(0);
                // v[i].push_back(-100000);
            for(int j = 0;j<cnt;j++){
                scanf("%d",&a);
                v[i].push_back(v[i][v[i].size()-1]+a);
            }
            for(int j = 0;j<n-i;j++)
                v[i].push_back(v[i][v[i].size()-1]);
                // v[i].push_back(v[i][v[i].size()-1] -100000);
            cnt += 2;
        }
        tri.clear();
        int maxi = -INF;
        int siz = 1;
        while(siz<=n){
            int ret = retMax(siz);
            maxi = max(maxi,ret);
            siz++;
        }
        printf("%d. %d\n",tc++,maxi);
    }
}