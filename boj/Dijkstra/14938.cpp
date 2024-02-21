#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);
    int item[100];
    for(int i = 0; i < n; i++){
        scanf("%d", &item[i]);
    }
    int dist[100][100];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            dist[i][j] = 987654321;
        }
        dist[i][i] = 0;
    }
    for(int i = 0; i < r; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        dist[a-1][b-1] = min(dist[a-1][b-1], c);
        dist[b-1][a-1] = min(dist[b-1][a-1], c);
    }
    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        int temp = 0;
        for(int j = 0; j<n; j++){
            if(dist[i][j] <= m){
                temp += item[j];
            }
        }
        ans = max(ans, temp);
    }
    printf("%d\n", ans);
    return 0;
}