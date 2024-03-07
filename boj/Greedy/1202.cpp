#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    pair<int, int> jewel[300000];
    for(int i = 0; i<N; i++){
        scanf("%d %d", &jewel[i].first, &jewel[i].second);
    }
    sort(jewel, jewel+N);
    int bag[300000];
    for(int i = 0; i<K; i++){
        scanf("%d", &bag[i]);
    }
    sort(bag, bag+K);
    priority_queue<int> pq;
    int idx = 0;
    long long ans = 0;
    for(int i = 0; i<K; i++){
        while(idx < N && jewel[idx].first <= bag[i]){
            pq.push(jewel[idx++].second);
        }
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }
    printf("%lld\n", ans);
    return 0;
}