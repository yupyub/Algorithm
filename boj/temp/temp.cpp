#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> upper[2001];
vector<int> start;
int visit[2001] = { 0, };
int numofmove = 0;
int dfs(int top);
vector<int> resultofdfs;

int main() {
    int numofsold;
    int whose;
    scanf("%d", &numofsold);
    for (int i = 1; i <= numofsold; i++) {
        scanf("%d", &whose);
        if (whose == -1)
            start.push_back(i);
        else
            upper[whose].push_back(i);
    }

    for (int j = 0; j < start.size(); j++) {
        resultofdfs.push_back(dfs(start[j]));
        for (int k = 0; k < 2001; k++) {
            visit[k] = 0;
        }
    }

    sort(resultofdfs.begin(), resultofdfs.end());
    printf("%d", resultofdfs.back());
    return 0;
}

int dfs(int top) {
    visit[top] = 1;
	int max_depth = 0;
    for (int i = 0; i < upper[top].size(); i++) {
        int nx = upper[top][i];
        if (visit[nx] == 0) {
            max_depth = max(dfs(nx),max_depth);
        }
    }
    return max_depth + 1;
}









