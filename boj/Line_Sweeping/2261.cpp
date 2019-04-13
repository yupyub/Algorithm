#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
vector<pair<int,int> >pos;
set<pair<int,int> >s;
int dist(pair<int,int>a, pair<int,int> b){
    return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}
pair<int,int> rev(pair<int,int> a){
    return make_pair(a.second,a.first);
}
int main(){
    int n,a,b;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d%d",&a,&b);
        pos.push_back(make_pair(a,b));
    }
    sort(pos.begin(),pos.end());
    int st = 0;
    int ans = dist(pos[0],pos[1]);
    s.insert(rev(pos[0]));
    s.insert(rev(pos[1]));
    for(int i = 2;i<n;i++){
        while(st<i){
            int x = pos[st].first - pos[i].first;
            if(x*x > ans){
                s.erase(rev(pos[st]));
                st++;
            }
            else break;
        }
        int y = (int)sqrt((double)ans) + 1;
        auto lo = s.lower_bound(rev(make_pair(-100000,pos[i].second - y)));
        auto up = s.upper_bound(rev(make_pair(100000,pos[i].second + y)));
        for(auto it = lo; it != up; it++){
            int d = dist(rev(pos[i]),*it);
            if(d<ans){
                ans = d;
            }
        }
        s.insert(rev(pos[i]));
    }
    printf("%d\n",ans);
}
