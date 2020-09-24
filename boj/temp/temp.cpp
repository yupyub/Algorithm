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
iHeap up, lo;
void f_pop(int x){
    int up_val = up.size() ? up.top() : INF;
    // empty exaption 처리 안되어있음
    if(x<=up_val){
        up.remove(x);
    }
    else{
        lo.remove(-x);
    }
    while(up.size()>1+lo.size()){
        lo.push(-up.top());
        up.remove(up.top());
    }
    while(lo.size()>up.size()){
        up.push(-lo.top());
        lo.remove(lo.top());
    }
}
void f_push(int x){
    int up_val = up.size() ? up.top() : INF;
    if(x<=up_val){
        up.push(x);
    }
    else{
        lo.push(-x);
    }
    while(up.size()>1+lo.size()){
        lo.push(-up.top());
        up.remove(up.top());
    }
    while(lo.size()>up.size()){
        up.push(-lo.top());
        lo.remove(lo.top());
    }
}
int f_mid(){
    return up.top();
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
        up.init();
        lo.init();
        for(int j = 0;j<w;j++)
            for(int k = 0;k<w;k++)
                f_push(arr[i+j][k]);
        printf("%d ",f_mid());
        for(int j = 0;j<m-w;j++){
            for(int k = 0;k<w;k++){
                f_pop(arr[i+k][j]);
                f_push(arr[i+k][j+w]);
            }
            printf("%d ",f_mid());
        }
        printf("\n");
    }
}