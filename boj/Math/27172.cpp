#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    int num[100000];
    int ordered[100000];
    map<int, int> score;
    for(int i = 0; i<N; i++){
        scanf("%d", &num[i]);
        ordered[i] = num[i];
        score[num[i]] = 0;
    }
    sort(ordered, ordered+N);
    for(int i = 0; i<N; i++){
        int mu = 2;
        while(ordered[i] * mu <= 1000000){
            if(score.find(ordered[i] * mu) != score.end()){
                score[ordered[i] * mu] -= 1;
                score[ordered[i]] += 1;
            }
            mu++;
        }
    }
    for(int i = 0; i<N; i++){
        printf("%d ", score[num[i]]);
    }
    return 0;
}