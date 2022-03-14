#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,int> > X;
vector<pair<int,int> > Y;
bool comp(const pair<int,int> &a, const pair<int,int> &b){
    return a.first < b.first;
}
int main(){
    int N, M, idx, num;
    scanf("%d", &N);
    for(int i = 0;i<N;i++){
        scanf("%d %d",&idx,&num);
        X.push_back(make_pair(idx,num));
    }
    scanf("%d", &M);
    for(int i = 0;i<M;i++){
        scanf("%d %d",&idx,&num);
        Y.push_back(make_pair(idx,num));
    }
    vector<int>Y_accum;
    Y_accum.resize(Y.size());
    Y_accum[0] = Y[0].second;
    for(int i = 1;i<M;i++)
        Y_accum[i] = Y[i].second + Y_accum[i-1];

    int t_start, t_end;
    scanf("%d %d", &t_start, &t_end);
    long long ans = 0;
    for(pair<int,int> el : X){
        int idx = el.first;
        int num = el.second;
        int start_idx = lower_bound(Y.begin(), Y.end(), make_pair(idx+t_start, 0), comp)-Y.begin() - 1;
        int end_idx = upper_bound(Y.begin(), Y.end(), make_pair(idx+t_end, 0), comp)-Y.begin() - 1;
        //printf("%d %d", start_idx, end_idx);
        //printf(">> %d %d\n", num, (Y_accum[end_idx] - Y_accum[start_idx]));
        ans += (long long)num * (Y_accum[end_idx] - Y_accum[start_idx]);
    }
    printf("%lld\n",ans);
    return 0;
}
