#include <iostream>
#include <utility>
using namespace std;

int n;
int nxt[1000000], indeg[1000000];
bool visit[1000000];

void proc() {
    cin >> n;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        int dist;
        char dir;
        cin >> dist >> dir;

        int ni = i, nj = j;
        switch (dir) {
            case 'U': ni -= dist; break;
            case 'D': ni += dist; break;
            case 'L': nj -= dist; break;
            case 'R': nj += dist; break;
        }
        nxt[i * n + j] = ni * n + nj;
        indeg[ni * n + nj] += 1;
    }

    int st = -1;
    for (int i = 0; i < n * n; ++i) {
        if (indeg[i] == 0) {
            st = i;
            break;
        }
    }
    if (st == -1) st = 0;

    int cnt = 0;
    for (int cur = st; !visit[cur]; cur = nxt[cur]) {
        ++cnt;
        visit[cur] = true;
    }

    if (cnt == n * n && indeg[st] == 0) {
        cout << st / n + 1 << ' ' << st % n + 1;
    }
    else if (cnt == n * n) {
        cout << "THIEF LOVE IT!";
    }
    else {
        cout << "TOO SAFE";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    proc();
    return 0;
}