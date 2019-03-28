#include <cstdio>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define LSOne(a) (a&(-a))
typedef vector<vector<int> > vvi;
class FenwickTree2D{
    private : 
        vvi ft;
        int N,M;

    public : FenwickTree2D(int n,int m){
                 ft.resize(n+1);
                 for(int i = 0;i<=n;i++){
                     ft[i].assign(n+1,0);
                 }
                 N = n;
                 M = m;
             }
             void adjust(int x,int y,int v){
                 int y1;
                 while(x<=N){
                     y1 = y;
                     while(y1<=M){
                         ft[x][y1] += v;
                         y1 += LSOne(y1);
                     }
                     x+=LSOne(x);
                 }
             }
             void adjust(int x1,int y1,int x2,int y2,int v){
                 adjust(x1,y1,v);
                 adjust(x2+1,y1,-v);
                 adjust(x1,y2+1,-v);
                 adjust(x2+1,y2+1,v);
             }
             int rsq(int x,int y){
                 int sum = 0;
                 for(;x;x-=LSOne(x)){
                     int y1 = y;
                     for(;y1;y1-=LSOne(y1)){
                         sum += ft[x][y1];
                     }
                 }
                 return sum;
             }
             int rsq(int x1,int y1,int x2,int y2){
                 return rsq(x2,y2)-rsq(x2,y1-1)-rsq(x1-1,y2) + rsq(x1-1,y1-1);
             }
};
vector<tuple<int,int,int,int> >rec;
vector<int> X,Y;
int main(){
    int n,a,b,c,d;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        rec.push_back(make_tuple(a,b,c,d));
        X.push_back(a);
        X.push_back(c);
        Y.push_back(b);
        Y.push_back(d);
    }
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    FenwickTree2D ft(X.size()+2,Y.size()+2);
    for(int i = 0;i<rec.size();i++){
        a = get<0>(rec[i]);
        b = get<1>(rec[i]);
        c = get<2>(rec[i]);
        d = get<3>(rec[i]);
        a = lower_bound(X.begin(),X.end(),a) - X.begin();
        b = lower_bound(Y.begin(),Y.end(),b) - Y.begin();
        c = lower_bound(X.begin(),X.end(),c) - X.begin();
        d = lower_bound(Y.begin(),Y.end(),d) - Y.begin();
        ft.adjust(a+1,b+1,c+1,d+1,1);
    }
    int ans = -1;
    int cnt = 0;
    for(int i = 0;i<rec.size();i++){
        a = get<0>(rec[i]);
        b = get<1>(rec[i]);
        a = lower_bound(X.begin(),X.end(),a) - X.begin();
        b = lower_bound(Y.begin(),Y.end(),b) - Y.begin();
        int tmp = ft.rsq(a+1,b+1);
        if(ans<tmp){
            ans = tmp;
            cnt = 1;
        }
        else if(ans == tmp){
            cnt++;
        }
    }
    printf("%d %d\n",ans,cnt);
}
