// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces/atcoder template
//   Address :   https://atcoder.jp/contests/abc175/tasks/abc175_c
//   Date    :   2020/08/15
// =====================================================

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < int(b); ++i)
typedef long long LL;

const int INF = (1<<31)-1;
const LL LL_INF = (1ll << 63)-1;
const int MOD = 1e9+7;

LL gcd (LL a, LL b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

void solve() {
    LL X, K, D;
    cin >> X >> K >> D;
    LL Y = abs(X);
    if (Y / D > K) {
        cout << Y-D*K << endl;
    } else {
        if (Y/D %2 == K%2) {
            cout << Y%D << endl;
        } else {
            cout << abs(Y%D-D) << endl;
        }
    }
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
