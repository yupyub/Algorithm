#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int main() {
	int N;
	cin >> N;
	string tmp;
	vector<string> str;
	pair<int,int> pos[26][2]; // 1µî & 2µî
	for (int i = 0; i < 26; i++)
		pos[i][0] = pos[i][1] = make_pair(INF,0);
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		str.push_back(tmp);
		for (int j = 0; j < tmp.length(); j++) {
			int c = tmp[j] - 'a';
			if (pos[c][0].first > j) 
				pos[c][0] = make_pair(j, i);
			else if (pos[c][0].first == j) 
				pos[c][0] = make_pair(j, -1);
			else if (pos[c][1].first > j) 
				pos[c][1] = make_pair(j, i);
			else if (pos[c][1].first == j) 
				pos[c][1] = make_pair(j, -1);
		}
	}
	int ans = INF;
	for (int i = 0; i < N; i++) {
		for (int j = str[i].length() - 1; j >= 0; j--) {
			if (pos[str[i][j]-'a'][0].first == INF)
				continue;
			if (pos[str[i][j]-'a'][0].second != i)
				ans = min(ans, pos[str[i][j]-'a'][0].first + (int)(str[i].length() - j - 1));
			if (pos[str[i][j]-'a'][1].second != i)
				ans = min(ans, pos[str[i][j] - 'a'][1].first + (int)(str[i].length() - j - 1));
		}
	}
	printf("%d", ans == INF ? -1 : ans);
}