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
char arr[10][10];
int n,m,k;
int cache[10000];
int dfs(int bit,int cnt){
    //printf("%u %d\n",bit, cnt);
    int& ret = cache[bit];
    if(cnt == k)
        ret = 1;
    else
        ret = 0;
    for(int i = 0;i<n;i++){
        if(bit& (1<<i))
            continue;
        int tmp = bit | (1<<i);
        //cout << tmp << endl;
        if(cache[tmp] != -1)
            continue;
        int tot = 0;
        for(int j = 6;j<m+6;j++)
            if((!(bit&(1<<j))) && arr[i][j-6] == '#')
                tot++;
        ret += dfs(tmp,cnt-tot);
    }
    for(int i = 6;i<m+6;i++){
        if(bit & (1<<i))
            continue;
        int tmp = bit | (1<<i);
        if(cache[tmp] != -1)
            continue;
        int tot = 0;
        for(int j = 0;j<n;j++)
            if((!(bit&(1<<j))) && arr[j][i-6] == '#')
                tot++;
        ret += dfs(tmp,cnt-tot);
    }
    return ret;
}
int main(){
    cin >> n >> m >> k;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int cnt = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(arr[i][j] == '#')
                cnt++;
        }
    }
    for(int i = 0;i<10000;i++)
        cache[i] = -1;
    cout << dfs(0,cnt) << endl;
}