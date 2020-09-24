#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <tuple>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = 987654321;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
ll arr[300002];
int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        int n, q;
        scanf("%d%d", &n, &q);
        for (int i = 0; i < n; i++)
            scanf("%lld", &arr[i+1]);
        arr[n + 1] = 0;
        ll ans = 0;
        for (int i = 0; i < n; i++)
            ans += arr[i+1] - arr[i + 2] > 0 ? arr[i+1] - arr[i + 2] : 0;
        printf("%lld\n", ans);
        for (int i = 0; i < q; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            if (a > b)
                swap(a, b);
            if (abs(b-a) == 1){
            if (arr[a - 1] > arr[a])
               ans -= arr[a - 1] - arr[a];
            if (arr[a] > arr[a + 1])
               ans -= arr[a] - arr[a + 1];
            if (arr[b] > arr[b + 1])
               ans -= arr[b] - arr[b + 1];

            swap(arr[a],arr[b]);

            if (arr[a - 1] > arr[a])
               ans += arr[a - 1] - arr[a];
            if (arr[a] > arr[a + 1])
               ans += arr[a] - arr[a + 1];
            if (arr[b] > arr[b + 1])
               ans += arr[b] - arr[b + 1];

            printf("%lld\n", ans);
            continue;
         }

         if (arr[a - 1] > arr[a])
            ans -= arr[a - 1] - arr[a];
         if (arr[a] > arr[a + 1])
            ans -= arr[a] - arr[a + 1];

         if (arr[b - 1] > arr[b])
            ans -= arr[b - 1] - arr[b];
         if (arr[b] > arr[b + 1])
            ans -= arr[b] - arr[b + 1];

         swap(arr[a],arr[b]);

         if (arr[a - 1] > arr[a])
            ans += arr[a - 1] - arr[a];
         if (arr[a] > arr[a + 1])
            ans += arr[a] - arr[a + 1];

         if (arr[b - 1] > arr[b])
            ans += arr[b - 1] - arr[b];
         if (arr[b] > arr[b + 1])
            ans += arr[b] - arr[b + 1];

         printf("%lld\n", ans);
      }
   }
}
