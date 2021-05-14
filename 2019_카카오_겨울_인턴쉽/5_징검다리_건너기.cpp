#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int s = 0;
    int e = 200000000;
    while(s<=e){
        int m = (s+e)/2;
        vector<int> temp;
        for(int i : stones){
            if(i<m-1)
                temp.push_back(0);
            else
                temp.push_back(i-m+1);
        }
        int accum = 0;
        int flag = 0;
        for(int i : temp){
            if(i != 0)
                accum = 0;
            else
                accum++;
            if(accum >= k){
                flag = 1;
                break;
            }
        }
        if(flag)
            e = m-1;
        else{
            answer = max(answer,m);
            s = m+1;
        }
    }
    return answer;
}