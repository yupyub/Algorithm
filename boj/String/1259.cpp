#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

bool is_palindrome(string s){
    int s_idx = 0;
    int e_idx = s.length() - 1;
    while(s_idx < e_idx){
        if(s[s_idx] != s[e_idx])
            return false;
        s_idx += 1;
        e_idx -= 1;
    }
    return true;
}

int main(){
    while(true){
        string s;
        cin >> s;
        if(s.compare("0") == 0)
            break;
        cout << (is_palindrome(s) ? "yes" : "no") << endl;
    }
    return 0;
}