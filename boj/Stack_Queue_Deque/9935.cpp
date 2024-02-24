#include <cstdio>
#include <stack>
#include <cstring>
#include <utility>
using namespace std;

int main(){
    char str[1000001];
    char bomb[37];
    scanf("%s", str);
    scanf("%s", bomb);
    int l_str = strlen(str);
    int l_bomb = strlen(bomb);
    stack<char> st1;
    stack<char> st2;
    for(int i = 0; i<l_str; i++){
        st1.push(str[i]);
        int i_bomb = l_bomb - 1;
        while(!st1.empty() && i_bomb >= 0){
            if(st1.top() == bomb[i_bomb]){
                i_bomb--;
                st2.push(st1.top());
                st1.pop();
            }
            else{
                break;
            }
            
        }
        if(i_bomb < 0){
            while(!st2.empty()){
                st2.pop();
            }
        }
        else{
            while(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
        }
    }
    char ans[1000001];
    int ans_i = 0;
    while(!st1.empty()){
        st2.push(st1.top());
        st1.pop();
    }
    while(!st2.empty()){
        ans[ans_i++] = st2.top();
        st2.pop();
    }
    if(ans_i == 0){
        printf("FRULA\n");
    }
    else{
        ans[ans_i] = '\0';
        printf("%s\n", ans);
    }
    return 0;
}