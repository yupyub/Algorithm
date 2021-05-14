#include <string>
#include <vector>
#include <map>
using namespace std;
map<long long,long long> m;
long long parent(long long x){
    if(m[x] == 0)
        return m[x] = x;
    else
        return m[x];
}
long long find(long long x){
    if(x == parent(x))
        return x;
    return m[x] = find(m[x]);
}
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(long long room : room_number){
        long long pos = find(room);
        answer.push_back(pos);
        m[pos] = parent(pos+1);
    }
    return answer;
}