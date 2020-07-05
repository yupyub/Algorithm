#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<cmath>
#include<cstdlib>
#include<functional>
#include<numeric>
using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iiint;
typedef pair<int, ii> intii;

const int inf = INT_MAX;


ll arr[1'000'005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, c, d; cin >> a >> b >> c >> d;

    ii x = ii(a, b);
    ii y = ii(b, c);
    ii z = ii(c, d);

    int m = min(b - a, c - b) + 1;

    int ii = 1, jj = 1;
    int i;

    for (int i = a + b; i <= b + c; i++) arr[i] = m;
    for (int i = a + b; ii < m; i++) arr[i] = ii++;
    for (int i = b+c; jj < m; i--) arr[i] = jj++;

    /*
    cout << a + b << endl;
    cout << a + c << endl;
    cout << b + c << endl;
    for (int i = a + b; i < b + c; i++) {
        cout << i << " : " << arr[i] << endl;
    }
    //--------------
    */
    for (int i = 1; i < 1'000'001; i++) {
        arr[i] += arr[i - 1];
    }


    //z < a+b
    ll ans = 0;
    for (int i = z.first; i <= z.second; i++) {
        ans += (arr[x.second + y.second] - arr[i]);
    }

    cout << ans << endl;

    return 0;
}