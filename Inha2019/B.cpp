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
map <string,int> Name;
int arr[1001];
int main(){
    ios_base::sync_with_stdio(false);
    int N,P,W,L,G;
	scanf("%d %d %d %d %d",&N,&P,&W,&L,&G);
    char tmp[30];
    char C;
    for(int i = 0;i<P;i++){
        scanf("%s %c",tmp,&C);
        string str(tmp);
        //printf(">>%s %c\n",tmp,C);
        if(Name[str] == 0)
            Name[str] = i+1;
        arr[Name[str]] = C == 'W' ? 1:0;
    }
    int tot = 0;
    for(int i = 0;i<N;i++){
        scanf("%s",tmp);
        string str(tmp);
        if(Name[str] == 0)
            tot -= L;
        else{
            if(arr[Name[str]]){
                tot += W;
            }
            else 
                tot -= L;
        }
        if(tot<0)
            tot = 0;
        if(tot >= G){
            printf("I AM NOT IRONMAN!!\n");
            return 0;
        }
    }
    printf("I AM IRONMAN!!\n");
}