// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1395/C
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
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(m);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int j = 0; j < m; ++j)
            cin >> b[j];
        set<int> cur, pre;
        for (int j = 0; j < m; ++j)
            cur.insert(a[0] & b[j]);
        for (int i = 0; i < n; ++i) {
            pre = cur;
            cur.clear();
            for (int j = 0; j < m; ++j) {
                int c = a[i] & b[j];
                for (auto &k: pre) {
                    cur.insert(c|k);
                }
            }
        }

        cout << *cur.begin();

    }

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
