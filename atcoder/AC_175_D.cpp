// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces/atcoder template
//   Address :   https://atcoder.jp/contests/abc175/tasks/abc175_d
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
 
void solve() {
    int n;
    LL K;
    cin >> n >> K;
    vector<int> P(n+1);
    for (int i = 1; i <= n; ++i)
        cin >> P[i];
    vector<LL> C(n+1);
    for (int i = 1; i <= n; ++i)
        cin >> C[i];
 
 
    LL ans = C[1];
    for (int i = 1; i <= n; ++i) {
        int start = P[i];
        int cur = P[start];
        LL score = C[start];
        ans = max(ans, score);
        LL count = 1;
 
        vector<LL> rem(1, 0);
        while (count < K && cur != start) {
            rem.push_back(score);
            ++count;
            score += C[cur];
            ans = max(ans, score);
            cur = P[cur];
        }
        if (count < K && cur == start) {
 
            LL rep = K / count;
            LL new_k = K % count;
 
            if (new_k == 0) {
                --rep;
                rem.push_back(score);
                new_k = count;
            }
 
            LL lar = rem[0];
            for (LL j = 1; j <= new_k; ++j)
                lar = max(lar, rem[j]);
            LL p = rep * score + lar;
            ans = max(ans, p);
 
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