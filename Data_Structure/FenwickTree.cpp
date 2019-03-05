#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define LSOne(a) (a&(-a))
class FenwickTree{
    private: 
             vector <long long> ft;
    public: 
             FenwickTree(int n) {
                 ft.assign(n+1,0);
             }
             ll rsq(int b){
                 ll sum = 0;
                 for(;b;b-=LSOne(b)) sum += ft[b];
                 return sum;
             }
             ll rsq(int a,int b){
                 return rsq(b) - (a == 1?0 : rsq(a-1));
             }
             void adjust(int k,ll v){
                 for(;k<(int)ft.size();k+=LSOne(k)) ft[k] += v;
             }
};
