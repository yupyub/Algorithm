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

int main(){
    ll n;
    scanf("%lld",&n);
    n--;
    vector<char> ans;
    while(n>=0){
        int ch = n%26;
        ans.push_back('a'+ch);
        n/=26;
        n--;
    }
    for(int i = ans.size()-1;i>=0;i--){
        printf("%c",ans[i]);
    }
    printf("\n");
}