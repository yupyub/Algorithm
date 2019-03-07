#include <cstdio>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long a = 0,b = 1,cnt = 1;
        long long x,y,n;
        scanf("%lld %lld",&x,&y);
        n = y-x;
        while(1){
            if(a<n && n<=a+b){
                printf("%lld\n",cnt);
                break;
            }
            a += b;
            cnt++;
            b+=cnt%2;
        }
    }
}
