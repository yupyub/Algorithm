#pragma GCC optimize("O3") 
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

void H(int n,char from,char to,char aux){
    if(n == 0)
        return;
    H(n-1,from,aux,to);
    printf("%c -> %c\n",from,to);
    H(n-1,aux,to,from);
}

int main(){
    int n;
    scanf("%d",&n);
    H(n,'A','C','B');
}