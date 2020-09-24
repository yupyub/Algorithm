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

int arr[300][300];
struct iHeap{
    priority_queue<int> q, qdel;
    void init(){
        while(!q.empty())
            q.pop();
        while(!qdel.empty())
            qdel.pop();
    }
    inline int size(){
        return q.size()-qdel.size();
    }
    inline void remove(int x){
        qdel.push(x);
    }
    inline void push(int x){
        q.push(x);
    }
    int top(){
        while(q.size() && qdel.size() && q.top() == qdel.top()){
            q.pop();
            qdel.pop();
        }
        return q.size() ? q.top() : -INF;
    }
};
iHeap up[301], lo[301];
void f_pop(int i,int x){
    int up_val = up[i].size() ? up[i].top() : INF;
    // empty exaption 처리 안되어있음
    if(x<=up_val){
        up[i].remove(x);
    }
    else{
        lo[i].remove(-x);
    }
    while(up[i].size()>1+lo[i].size()){
        lo[i].push(-up[i].top());
        up[i].remove(up[i].top());
    }
    while(lo[i].size()>up[i].size()){
        up[i].push(-lo[i].top());
        lo[i].remove(lo[i].top());
    }
}
void f_push(int i,int x){
    int up_val = up[i].size() ? up[i].top() : INF;
    if(x<=up_val){
        up[i].push(x);
    }
    else{
        lo[i].push(-x);
    }
    while(up[i].size()>1+lo[i].size()){
        lo[i].push(-up[i].top());
        up[i].remove(up[i].top());
    }
    while(lo[i].size()>up[i].size()){
        up[i].push(-lo[i].top());
        lo[i].remove(lo[i].top());
    }
}
int f_mid(int i){
    return up[i].top();
}
int main(){
    int n,m,w;
    scanf("%d %d %*d %d",&n,&m,&w);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i = 0;i<n-w+1;i++){
        if(i == 0){
            for(int j = 0;j<w;j++)
                for(int k = 0;k<w;k++)
                    f_push(300,arr[i+j][k]);
            up[i] = up[300];
            lo[i] = lo[300];
        }
        else{
            for(int j = 0;j<w;j++){
                f_pop(300,arr[i-1][j]);
                f_push(300,arr[i+w-1][j]);
            }
            up[i] = up[300];
            lo[i] = lo[300];
        }
        printf("%d ",f_mid(i));
        for(int j = 0;j<m-w;j++){
            for(int k = 0;k<w;k++){
                f_pop(i,arr[i+k][j]);
                f_push(i,arr[i+k][j+w]);
            }
            printf("%d ",f_mid(i));
        }
        printf("\n");
    }
}