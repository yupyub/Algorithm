#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) {
    map <string,int> m;
    int cnt = 1;
    for(auto s : gems){
        if(m[s] == 0)
            m[s] = cnt++;
    }
    /*
    for(auto i = m.begin();i != m.end();i++){
        cout << i->first << " " << i->second << endl;
    }
    */
    vector<int> answer;
    answer.push_back(1);
    answer.push_back(gems.size());
    vector<int> check;
    check.resize(m.size()+1);
    for(int i = 0;i<check.size();i++)
        check[i] = 0;
    int count = 0;
    int s = 0,e = -1;
    int len = gems.size();
    while(s < gems.size()){
        if(count < m.size()){
            e++;
            if(e>=gems.size())
                break;
            if(check[m[gems[e]]] == 0)
                count++;
            check[m[gems[e]]]++;
        }
        else{
            if(check[m[gems[s]]] == 1)
                count--;
            check[m[gems[s]]]--;
            s++;
        }
        if(count == m.size()){
            if(len > e-s+1){
                len = e-s+1;
                answer[0] = s+1;
                answer[1] = e+1;
            }
        }
    }
    return answer;
}