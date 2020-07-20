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
    int n;
    int pay = 1000;
    cin >> n;
    if(n%pay != 0)
        cout << pay-n%pay << endl;
    else
        cout << 0 << endl;
}