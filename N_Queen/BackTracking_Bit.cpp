#include <cstdio> //Solve the number of N-Queen
int ans;
int check;
void backtrack(int a,int b,int c){
    if(a == check){
        ans++;
        return;
    }
    int nxt = check &(~(a|b|c));
    while(nxt){
        int p =  nxt & -nxt;
        nxt -= p;
        backtrack(a|p,(b|p)<<1,(c|p)>>1);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    check = (1<<n)-1;
    backtrack(0,0,0);
    printf("%d",ans); 
}
