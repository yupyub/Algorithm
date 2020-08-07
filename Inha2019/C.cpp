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
int dx[] = {1,0};
int dy[] = {0,1};
int N;
int maxi = -INF;
int mini = INF;
char arr[5][5];
int oper(char op,int tot,int val){
    if(op == '+')
        tot += val;
    else if(op == '-')
        tot -= val;
    else if(op == '*')
        tot *= val;
    return tot;
}
void DFS(int x,int y,int tot,char op){
    //printf("%d %d %d %c\n",x,y,tot,op);
    if(x == N-1 && y == N-1){
        mini = min(mini,tot);
        maxi = max(maxi,tot);
        return;
    }
    if(x == 0 && y == 0)
        tot = arr[0][0] - '0';
    for(int i = 0;i<2;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        int tmptot = tot;
        char tmpop = op;
        if(nx < 0 || ny<0 || nx >=N || ny>=N)
            continue;
        if(arr[nx][ny]>='0' && arr[nx][ny]<'6')
            tmptot = oper(op,tot,arr[nx][ny]-'0');
        DFS(nx,ny,tmptot,arr[nx][ny]);
    }
}
int main(){
    scanf("%d",&N);
    scanf("%*c");
    for(int i = 0;i<N-1;i++){
        for(int j = 0;j<N;j++){
            scanf("%c ",&arr[i][j]);
        }
    }
    for(int j = 0;j<N-1;j++)
        scanf("%c ",&arr[N-1][j]);
    scanf("%c",&arr[N-1][N-1]);
    DFS(0,0,0,' ');
    printf("%d %d\n",maxi,mini);
}