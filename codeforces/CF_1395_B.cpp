// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1395/B
//   Date    :   2020/08/12
// =====================================================

//#define LOCAL
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long LL;

const int INF = (1<<31)-1;
const LL LL_INF = (1ll << 63)-1;
const int MOD = 1e9+7;

LL gcd (LL a, LL b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
freopen("data.in", "r", stdin);
while (!feof(stdin)) {
#endif // LOCAL

    int t;
    //cin >> t;
    t = 1;
    while (t--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        vector<int> pos_x;
        vector<int> pos_y;
        int idx = -1;
        for (int i = 1; i <= m; ++i) {
            pos_x.push_back(1);
            pos_y.push_back(i);
            if (x == 1 && y == i)
                idx = pos_x.size()-1;
        }
        for (int i = m; i > 0; --i) {
            if (i%2 == m%2) {
                for (int j = 2; j <= n; ++j) {
                    pos_x.push_back(j);
                    pos_y.push_back(i);
                    if (x == j && y == i)
                        idx = pos_x.size()-1;
                }
            } else {
                for (int j = n; j > 1; --j) {
                    pos_x.push_back(j);
                    pos_y.push_back(i);
                    if (x == j && y == i)
                        idx = pos_x.size()-1;
                }
            }
        }
        //cout << pos_x.size() << endl;
        for (int i = 0; i < m*n; ++i)
            cout << pos_x[(idx+i)%(m*n)] << " " << pos_y[(idx+i)%(m*n)] << endl;

    }

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
