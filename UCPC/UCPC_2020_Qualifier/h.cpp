#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector < int > heights;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, a;
    int c1, c2;

    c1 = c2 = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;

        if (a == 0) {
            continue;
        }

        c2 += a / 2;
        if (a % 2 == 1) {
            c1++;
        }
    }

    if (c1 > c2) {
        cout << "NO\n";
    }
    else if (c1 == c2) {
        cout << "YES\n";
    }
    else if ((c2 - c1) % 3 == 0){
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}
