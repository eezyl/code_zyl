// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces/atcoder template
//   Address :   https://atcoder.jp/contests/abc175/tasks/abc175_e
//   Date    :   2020/08/15
// =====================================================

#include <bits/stdc++.h>
using namespace std;

//#define rep(i, a, b) for (int i = (a); i < int(b); ++i)
typedef long long LL;

const int MOD = 1e9+7;

LL gcd (LL a, LL b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

LL g[3005][3005] = {};
LL dp[3005][3005][4] = {};
void solve() {
    int R, C, K;
    cin >> R >> C >> K;
    for (int i = 0; i < K; ++i) {
        int r, c;
        LL v;
        cin >> r >> c >> v;
        g[r][c] = v;
    }
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            for (int k = 0; k < 4; ++k)
                dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k]);
            if (g[i][j] != 0) {
                for (int k = 0; k < 4; ++k) {
                    dp[i][j][1] = max(dp[i][j][1], g[i][j] + dp[i-1][j][k]);
                }
                for (int k = 1; k < 4; ++k) {
                    dp[i][j][k] = max(dp[i][j][k], g[i][j] + dp[i][j-1][k-1]);
                }
            }
        }
    }
    LL ans = dp[R][C][0];
    for (int i = 1; i < 4; ++i)
        ans = max(ans, dp[R][C][i]);
    cout << ans << endl;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
//#define LOCAL
#ifdef LOCAL
freopen("data.in", "r", stdin);
while (!feof(stdin)) {
#endif // LOCAL

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
