nclude <cstdio> //Print the N_Queen table // Maximum : 31 (long long)
typedef long long ll;
int arr[32][32];
ll ans;
ll check;
ll n;
int tw(ll a){
    int ret = 0;
    while(a){
        a = a>>1;
        ret++;
    }
    return ret;
}
void backtrack(ll a,ll b,ll c,int cnt){
    if (ans != 0) return;
    if(a == check){
        ans++;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++)
                printf("%d ",arr[i][j]);
            printf("\n");
        }
        return;
    }
    ll nxt = check &(~(a|b|c));
    while(nxt){
        ll p =  nxt & -nxt;
        nxt -= p;
        int t = tw(p);
        arr[cnt][n-t] = 1;
        backtrack(a|p,(b|p)<<1,(c|p)>>1,cnt+1);
        arr[cnt][n-t] = 0;
    }
}
int main(){
    scanf("%lld",&n);
    check = (1<<n)-1;
    backtrack(0,0,0,0);
}
