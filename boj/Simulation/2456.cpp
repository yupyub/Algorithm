#include <cstdio>
#include <vector>
using namespace std;

vector<int> get_max(vector<int> candidate, int score[][4], int opt){
    int maxi = -1;
    vector<int> ret;
    for(int i : candidate){
        if(score[i][opt] > maxi){
            maxi = score[i][opt];
            ret.clear();
            ret.push_back(i);
        }
        else if(score[i][opt] == maxi){
            ret.push_back(i);
        }
    }
    return ret;
}

int main(){
    int N, a;
    int score[3][4] = {0, };
    int total[3] = {0, };
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        for(int j = 0; j<3; j++){
            scanf("%d", &a);
            score[j][a]++;
            score[j][0] += a;
        }
    }
    vector<int> candidate;
    candidate.push_back(0);
    candidate.push_back(1);
    candidate.push_back(2);
    for(int i = 0; i<3; i++){
        candidate = get_max(candidate, score, i);
    }
    if(candidate.size()>1){
        printf("0 %d\n", score[candidate[0]][0]);
    }
    else{
        printf("%d %d\n",candidate[0]+1, score[candidate[0]][0]);
    }
    return 0;
}