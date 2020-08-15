// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1391/B
//   Date    :   2020/08/09
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
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
freopen("data.in", "r", stdin);
while (!feof(stdin)) {
#endif // LOCAL

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        int ans = 0;
        for (int i = 0; i < m; ++i)
            if (a[n-1][i] == 'D')
                ++ans;
        for (int i = 0; i < n; ++i)
            if (a[i][m-1] == 'R')
                ++ans;
        cout << ans << endl;
    }

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
