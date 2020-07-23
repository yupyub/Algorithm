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
typedef unsigned long long int ull;
const int INF = 987654321;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
ull arr[200000];
int main(){
    ull tot = 0;
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%llu",&arr[i]);
        tot ^= arr[i];
    }
    for(int i = 0;i<n;i++){
        printf("%llu ",tot^arr[i]);
    }
    printf("\n");

}