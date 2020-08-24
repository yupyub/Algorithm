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
int N;
int a,b;
int isPrime[100001];
int visit[1000002];
void PR(){
    for(int i = 2;i<=100000;i++)
        isPrime[i] = 1;
    for(int i = 2;i<=sqrt(100000);i++){
        if(isPrime[i] == 0)
            continue;
        for(int j = i*2;j<=100000;j+=i)
            isPrime[j] = 0;
    }
}
int BFS(int t){
    queue<pair<int,int> >q;
    q.push(make_pair(N,0));
    visit[N] = t;
    while(!q.empty()){
        int n = q.front().first;
        int d = q.front().second;
        q.pop();
        if(n>1000000)
            continue;
        if(a<=n && n<=b && isPrime[n])
            return d;
        if(visit[n/2]<t){
            visit[n/2] = t;
            q.push(make_pair(n/2,d+1));
        }
        if(visit[n/3]<t){
            visit[n/3] = t;
            q.push(make_pair(n/3,d+1));
        }
        if(visit[n+1]<t){
            visit[n+1] = t;
            q.push(make_pair(n+1,d+1));
        }
        if(n != 0 && visit[n-1]<t){
            visit[n-1] = t;
            q.push(make_pair(n-1,d+1));
        }
    }
    return -1;
}
int main(){
    PR();
    int T;
    scanf("%d",&T);
    int t = 0;
    while(T--){
        t++;
        scanf("%d %d %d",&N,&a,&b);
        int flag = 0;
        for(int i = a;i<=b;i++){
            if(isPrime[i]){
                flag = 1;
                break;
            }
        }
        if(!flag){
            printf("%d\n",-1);
            continue;
        }
        printf("%d\n",BFS(t));
    }
}