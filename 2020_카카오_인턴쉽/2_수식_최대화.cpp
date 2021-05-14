#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
ll calc(long long a,long long b,char c){
    if(c == '*')
        return a * b;
    else if(c == '+')
        return a + b;
    else
        return a - b;
}
long long solution(string expression) {
    long long answer = 0;
    string priority = "+-*";
    sort(priority.begin(),priority.end());


    do{
        char str[101];
        vector<ll> num;
        strcpy(str,expression.c_str());
        char* token = strtok(str,"+-*");
        while(token != NULL ){
            num.push_back(atoi(token));
            token = strtok(NULL,"+-*");
        }
        vector<char> op;
        strcpy(str,expression.c_str());
        token = strtok(str,"0123456789");
        while(token != NULL){
            op.push_back(token[0]);
            token = strtok(NULL,"0123456789");
        }
        vector<ll> numtemp;
        vector<char> optemp;
        for(char C : priority){
            numtemp.push_back(num[0]);
            for(int i = 0;i<op.size();i++){
                if(op[i] == C){
                    ll nu = calc(numtemp.back(),num[i+1],C);
                    numtemp.pop_back();
                    numtemp.push_back(nu);
                }
                else
                    numtemp.push_back(num[i+1]);
            }
            num.clear();
            for(ll i : numtemp){
                num.push_back(i);
            }
            numtemp.clear();
            for(char c : op){
                if(c != C)
                    optemp.push_back(c);
            }
            op.clear();
            for(char c : optemp){
                op.push_back(c);
            }
            optemp.clear();
            /*
            printf("[%c]\n",C);
            for(ll i : num){
                printf("%d ",i);
            }
            printf("\n");
            for(char c : op){
                printf("%c ", c);
            }
            printf("\n");
            */
        }
        answer = max(answer,abs(num[0]));
    }while(next_permutation(priority.begin(),priority.end()));
    return answer;
}