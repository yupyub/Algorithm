#include <cstdio>
int main() {
    int n,a,b;
    a = 0;
    b = 1;
    scanf("%d\n",&n);
    while(1){
        if(a<n && n<=a+b){
            if(b%2) printf("%d/%d",b-n+a+1,n-a);    
            else printf("%d/%d",n-a,b-n+a+1);
            break;
        }
        a += b;
        b++;
    }
}
