#include <cstdio>
#include <stack>
#include <iostream>
#include <string>
using namespace std;


int main(){
    string form;
    cin >> form;
    string ans;
    stack<char> st;
    for(int i = 0; i< form.length(); i++){
        char c = form[i];
        if(c == '('){
            st.push(c);
        }
        else if(c == ')'){
            while(st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else if(c == '+' || c == '-'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
        else if(c == '/' || c == '*'){
            while(!st.empty() && st.top() != '(' && st.top() != '+' && st.top() != '-'){
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
        else {  // alphabet
            ans += c;
        }
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    cout << ans << endl;
    return 0;
}