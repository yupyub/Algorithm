#include <cstdio>
#include <vector>
using namespace std;
int is_prime[4100000];
int main(){
    int N;
    scanf("%d", &N);
    vector<int> prime;
    for(int i = 2; i<4100000; i++){
        if(!is_prime[i]){
            prime.push_back(i);
            int mul = 2;
            while(i * mul < 4100000){
                is_prime[i * mul] = 1;
                mul++;
            }
        }
    }
    int l = prime.size();
    int st = 0;
    int ed = 0;
    int sum = 0;
    int ans = 0;
    while(st < l){
        if(sum < N){
            sum += prime[ed++];
        }
        else if(sum > N){
            sum -= prime[st++];
        }
        else{
            ans++;
            sum -= prime[st++];
        }
    }
    printf("%d\n", ans);
    return 0;
}