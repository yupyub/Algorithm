#include <cstdio>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
class SegmentTree{
    private : 
        vector<int> st,A,lazy;
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
        void update_range(int p,int L,int R,int i,int j,int diff){
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
        SegmentTree(const vector<int> &_A){
            A = _A;
            n = (int)A.size();
            st.assign(4*n,0);
            lazy.assign(4*n,0);
            //build(1,0,n-1);
        }
        long long sum(int i,int j) { 
            return sum(1,0,n-1,i,j);
        }
        void update_range(int i,int j,int diff){
            update_range(1,0,n-1,i,j,diff);
        }
        void update(int i, int diff){
            update_range(1,0,n-1,i,i,diff);
        }
};
vector<tuple<int,int,int,int> >line;
vector<int> X,Y;
int main(){
    int n,a,b,c,d;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        line.push_back(make_tuple(a,b,d,1));
        line.push_back(make_tuple(c,b,d,-1)); 
        // The Sort order of -1,1 need not be considered. 
        // Because, lines are not overlapping
        X.push_back(a);
        X.push_back(c);
        Y.push_back(b);
        Y.push_back(d);
    }
    X.erase(unique(X.begin(),X.end()),X.end());
    Y.erase(unique(Y.begin(),Y.end()),Y.end());
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    sort(line.begin(),line.end());
    SegmentTree st(Y);
    int ans = -1,cnt = 0;
    int x,y1,y2,diff;
    for(int i = 0;i<line.size();i++){
        x = get<0>(line[i]);
        y1 = get<1>(line[i]);
        y2 = get<2>(line[i]);
        diff = get<3>(line[i]);
        x = lower_bound(X.begin(),X.end(),x) - X.begin();
        y1 = lower_bound(Y.begin(),Y.end(),y1) - Y.begin();
        y2 = lower_bound(Y.begin(),Y.end(),y2) - Y.begin();
        st.update_range(y1,y2,diff);
        int tmp = st.sum(y1,y1);
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
