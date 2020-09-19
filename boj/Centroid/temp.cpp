#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <tuple>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = 987654321;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int N;
vector<vector<int> > g;
vector<int>cent;
int trSize[100001];
int findCentroid(int nn){ // O(n)
    trSize[nn] = 1;
    int flag = 0;
    for(int nxt : g[nn]){
        if(trSize[nxt])
            continue;
        int siz = findCentroid(nxt);
        if(siz>N/2)
            flag = 1;
        trSize[nn] += siz;
    }
    if(N-trSize[nn]>N/2) 
        flag = 1;
    if(flag == 0)
        cent.push_back(nn);
    return trSize[nn];
}
int findCentroidForDecompose(int nn){ // O(n)
    trSize[nn] = 1;
    int flag = 0;
    for(int nxt : g[nn]){
        if(trSize[nxt])
            continue;
        int siz = findCentroid(nxt);
        if(siz>N/2)
            flag = 1;
        trSize[nn] += siz;
    }
    if(N-trSize[nn]>N/2) 
        flag = 1;
    if(flag == 0)
        cent.push_back(nn);
    return trSize[nn];
}
int decomposeTree(int node){
    
}
int main(){
    scanf("%d",&N);
    // g.clear();
    g.resize(N+1);
    int a,b;
    for(int i = 0;i<N-1;i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    // cent.clear();
    // for(int i = 0;i<=n;i++)
    //     trSize[i] = 0;
    findCentroid(1); // O(N)

}
