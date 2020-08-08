// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/contest/1393/problem/D
//   Date    :   2020/08/07
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

LL gcd (LL a, LL b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

int main()
{
#ifdef LOCAL
freopen("data.in", "r", stdin);
while (!feof(stdin)) {
#endif // LOCAL

    int n, m;
    scanf("%d %d", &n, &m);
    vector<string> board(n);
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        board[i] = str;
    }
    vector<vector<int> > dp(n, vector<int>(m, 1));
    LL ans = 0;
    for (int i = 2; i < n; ++i) {
        for (int j = 1; j < m-1; ++j) {
            char ch = board[i][j];
            int best = min({dp[i-1][j-1], dp[i-1][j+1], dp[i-2][j]});
            if (ch == board[i-1][j-1] && ch == board[i-1][j] && ch == board[i-1][j+1] && ch == board[i-2][j])
                dp[i][j] = best+1;
            else
                dp[i][j] = 1;
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            ans += dp[i][j];
    printf("%I64d\n", ans);

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
