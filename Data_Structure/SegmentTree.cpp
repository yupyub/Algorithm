#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
class SegmentTree{
    private : 
        vector<long long> st,A,lazy;
        int n;
        int left(int p) { return p<<1;}
        int right(int p) { return (p<<1)+1;}
        void build(int p,int L,int R){ //O(n)
            if(L == R) st[p] = A[L];
            else{
                build(left(p),L,(L+R)/2);
                build(right(p),(L+R)/2+1,R);
                st[p] = st[left(p)] + st[right(p)];
            }
        }
        void update_lazy(int p,int L,int R){
            if(lazy[p] != 0){
                st[p] += (R-L+1)*lazy[p];
                if(L!=R){
                    lazy[left(p)] += lazy[p];
                    lazy[right(p)] += lazy[p];
                }
                lazy[p] = 0;
            }
        }
        void update_range(int p,int L,int R,int i,int j,long long diff){
            update_lazy(p,L,R);
            if(i>R||j<L) return;
            if(i<=L && R<=j){
                st[p] += (R-L+1)*diff;
                if(L!=R){
                    lazy[left(p)] += diff;
                    lazy[right(p)] += diff;
                }
                return;
            }
            update_range(left(p),L,(L+R)/2,i,j,diff);
            update_range(right(p),(L+R)/2+1,R,i,j,diff);
            st[p] = st[left(p)] + st[right(p)];
        }
        long long sum(int p,int L,int R,int i,int j){
            update_lazy(p,L,R);
            if(i>R||j<L) return 0;
            if(i<=L&&R<=j) return st[p];
            return sum(left(p),L,(L+R)/2,i,j) + sum(right(p),(L+R)/2+1,R,i,j);
        }
    public :
        SegmentTree(const vector<long long> &_A){
            A = _A;
            n = (int)A.size();
            st.assign(4*n,0); // compact : 1<<(k+1) (n<=2^k)
            lazy.assign(4*n,0);
            build(1,0,n-1);
        }
        long long sum(int i,int j) { 
            return sum(1,0,n-1,i,j);
        }
        void update_range(int i,int j,long long diff){
            update_range(1,0,n-1,i,j,diff);
        }
        void update(int i, long long diff){
            update_range(1,0,n-1,i,i,diff);
        }
};

