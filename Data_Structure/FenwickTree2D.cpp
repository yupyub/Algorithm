#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define LSOne(a) (a&(-a))
class FenwickTree2D{
    private : 
        vector<vector<int> > ft;
        int N,M;

    public : FenwickTree2D(int n,int m){
                 ft.resize(n+1);
                 for(int i = 0;i<=n;i++){
                     ft[i].assign(m+1,0);
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
             void adjust(int x1,int y1,int x1,int x2,int v){
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
