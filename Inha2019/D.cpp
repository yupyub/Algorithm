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

int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    int maxi = 0;
    int a,b;
    scanf("%d",&a);
    maxi = a*2;
    for(int i = 0;i<M-1;i++){
        scanf("%d",&b);
        maxi = max(maxi,b-a);
        a = b;
    }
    maxi = max(maxi,(N-a)*2);
    printf("%d\n",(maxi+1)/2);
}