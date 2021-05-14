#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int> > v;
    string temp;
    for(int i = 1;i<s.length()-1;i++){
        if(s[i] == '{'){
            v.push_back(vector<int>());
        }
        else if(isdigit(s[i]))
            temp += s[i];
        else{
            if(temp.length() == 0)
                continue;
            v[v.size()-1].push_back(stoi(temp));
            temp = "";
        }
    }
    vector<pair<int,int> > vs;
    for(int i = 0;i<v.size();i++)
        vs.push_back(make_pair(v[i].size(),i));
    sort(vs.begin(),vs.end());
    map<int,int> m;
    for(auto i : vs){
        int idx = i.second;
        int new_num;
        for(int j : v[idx]){
            if(m[j] == 0){
                new_num = j;
                m[j] = 1;
                break;
            }
        }
        answer.push_back(new_num);
    }
    return answer;
}