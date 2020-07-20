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
    string a;
    map<string,int> m;
    cin >> n;
    m["AC"] = 0;
    m["WA"] = 0;
    m["TLE"] = 0;
    m["RE"] = 0;
    while(n--){
        cin >> a;
        m[a] = m[a]+1;
    }
    cout << "AC" << " x " <<  m["AC"] << endl;
    cout << "WA" << " x " <<  m["WA"] << endl;
    cout << "TLE" << " x " <<  m["TLE"] << endl;
    cout << "RE" << " x " <<  m["RE"] << endl;
}