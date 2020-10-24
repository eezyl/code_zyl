// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces/atcoder template
//   Address :   https://atcoder.jp/contests/abc175/tasks/abc175_b
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
    int n;
    cin >> n;
    vector<LL> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (n < 3) {
        printf("0\n");
        return;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (a[i] == a[j])
                continue;
            for (int k = j+1; k < n; ++k) {
                if (a[k] == a[j])
                    continue;
                if (a[i]+a[j] > a[k])
                    ++ans;
            }
        }
    }
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
