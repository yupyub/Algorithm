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
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int N,M;
int arr[200000];
vector<pair<int,int> > v;
int main(){
    scanf("%d %d",&N,&M);
    int mi = 0;
    int pl = 0;
    int zr = 0;
    for(int i = 0;i<N;i++){
        scanf("%d",&arr[i]);
        v.push_back(make_pair(abs(arr[i]),arr[i]));
        if(arr[i]<0)
            mi++;
        if(arr[i] == 0)
            zr++;
    }
    pl = N-mi-zr;
    sort(v.begin(),v.end());
    int ans = 0;
    if(pl+mi < M)
        ans = 0;
    else{
        if(M%2 && pl){
            
        }
    }

}