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
typedef pair<int,int> ii;
const int INF = 987654321;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int N,M;
vector<int> v;
int idx = 0;
void printNum(){
    ll tmp = 0;
    ll two = 1;
    for(int i = 0;i<=idx;i++){
        if(v[i])
            tmp += two;
        two *= 2;
    }
    printf("%lld ",tmp);
}
int main(){
    ll X;
    int N;
    scanf("%lld %d",&X,&N);
    while(X){
        v.push_back((int)(X%2));
        X /= 2;
    }
    int val = 1;
    int cnt = v[0];
    for(int i = 1;i<v.size();i++){
        val *= 2;
        if(v[i] == 1)
            cnt++;
    }
    if(cnt<N){
        printf("-1\n");
        return 0;
    }
    N--;
    idx = v.size()-1;
    while(N--){
        while(v[idx] == 0)
            idx--;
        idx--;
        printNum();
    }
    printf("0\n");
}