#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int gcd(int a, int b){
    if(a < b)
        swap(a, b);
    return b ? gcd(b, a%b) : a;
}

int arr[200000];

int dq(int s, int e){
    int L = e - s;
    if(L == 1){
        return arr[s];
    }
    int e1 = L/2;
    int e2 = (L+1)/2;
    int ret = 0;
    // case 1
    int temp = arr[s];
    for(int i = s+1; i<s + e1; i++){
        temp = gcd(temp, arr[i]);
    }
    ret = max(ret, temp + dq(e-e2, e));
    // case 2
    temp = arr[e-e2];
    for(int i = e-e2+1; i<e; i++){
        temp = gcd(temp, arr[i]);
    }
    ret = max(ret, temp + dq(s, s+e1));
    return ret;
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    printf("%d\n", dq(0, N));
    return 0;
}