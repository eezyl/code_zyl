// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1398/D
//   Date    :   2020/08/14
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

int r[205] = {};
int g[205] = {};
int b[205] = {};
int dp[205][205][205] = {0};

int helper(int c, int d, int e) {
    if (c == 0 && d == 0)
        return 0;
    if (d == 0 && e == 0)
        return 0;
    if (c == 0 && e == 0)
        return 0;

    if (!dp[c][d][e]) {
        int p = 0, q = 0, s = 0;
        if (c>0 && d>0)
            p = helper(c-1, d-1, e) + r[c]*g[d];
        if (d > 0 && e > 0)
            q = helper(c, d-1, e-1) + g[d]*b[e];
        if (c > 0 && e > 0)
            s = helper(c-1, d, e-1) + r[c]*b[e];
        dp[c][d][e] = max({p,q,s});
    }
    return dp[c][d][e];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
freopen("data.in", "r", stdin);
while (!feof(stdin)) {
#endif // LOCAL

    int t = 1;
    //cin >> t;
    while (t--) {
        int R, G, B;
        cin >> R >> G >> B;
        for (int i = 1; i <= R; ++i)
            cin >> r[i];
        for (int i = 1; i <= G; ++i)
            cin >> g[i];
        for (int i = 1; i <= B; ++i)
            cin >> b[i];
        sort(r+1, r+R+1);
        sort(g+1, g+G+1);
        sort(b+1, b+B+1);

        cout << helper(R, G, B) << endl;


    }

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
